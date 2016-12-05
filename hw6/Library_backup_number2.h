#include <iostream>
#include <string>

using namespace std;
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

struct Book {
  Book() = delete;
  Book(string _isbn, string _title, string _author) : isbn(_isbn), title(_title), author(_author) {};

  string isbn;
  string title;
  string author;

  bool operator<(const Book &other) { return isbn < other.isbn; };
  bool operator>(const Book &other) { return isbn > other.isbn; };
  bool operator==(const Book &other) { return isbn == other.isbn; };
  bool operator!=(const Book &other) { return isbn != other.isbn; };

};

class Library {
 public:
  Library();
  void add(Book);
  void check_in(Book);
  Book *check_out(Book);
  Book *search(Book);
  long available_copies(Book);
  //int *temp_root;
  

 private:
  struct BookNode {
    Book value;
    BookNode *left;
    BookNode *right;
    size_t count = 1;
    BookNode(Book b) : value(b), left(nullptr), right(nullptr) {};
  };
  BookNode *root;
  void add(BookNode *&root_node, BookNode *&new_node);
  BookNode *search(Book, BookNode *root);
  void display(BookNode *current_node); //*************
};





void Library::display(BookNode *current_node)
{
	cout << "... Displaying contents of Library..." << endl;
	
	if (current_node->left != nullptr)
	{
		cout << "went left" << endl;
		display(current_node->left);
	}
	
	if ( current_node->right != nullptr)
	{
		cout << "went right" << endl;
		display(current_node->right);
	}
	
	
	cout << endl << "isbn: " << current_node->value.isbn << endl;
	cout << "title: " << current_node->value.title << endl;
	cout << "author: " << current_node->value.author << endl << endl;
}





Library::Library()
{
	this->root = nullptr;
}












void Library::add(Book val)
{	
	cout << "adding: " << val.title << endl; /////////////////////////////
	
	if(this->root == nullptr)
	{
		BookNode temp_node(val);
		root = &temp_node;
		//*root = &temp_node;
		////////
		cout << "value at library root: " << this->root->value.title << endl; // remove 
		//display(this->root);
		////////
		return;
	}
	
	cout << "value at library root: " << this->root->value.title << endl; // remove
	
	/*
	if(search(val) != nullptr)
	{
		cout << "value at library root: " << this->root->value.title << endl; ///////
		cout << "This library already contains that book. (" << val.title << ")" << endl;
		return;
	}
	*/
	
	
	cout << "value at library root: " << this->root->value.title << endl; // remove
	BookNode *current_node = root;
	cout << "value at library root: " << root->value.title << endl; // remove
	
	while(true)
	{
		if(current_node->value < val)
		{
			cout << "FIRST IF.....current_node->value < val" << endl; // remove
			if(current_node->right == nullptr)
			{
				// current_node.right must become a BookNode with value = val
				BookNode temp = *root;
				BookNode temp_node(val);
				root = &temp;
				root->right = &temp_node;
				display(root);
				return;
			}
			else 
			{
				current_node = current_node->right;
				continue;
			}
		}
		
		if(current_node->value > val)
		{
			cout << "SECOND IF.....current_node->value > val" << endl; // remove
			if(current_node->left == nullptr)
			{
				cout << "value at library root: " << root->value.title << endl; // remove
				cout << "author: " << root->value.author << endl;
				BookNode temp = *root;
				BookNode temp_node(val);
				root = &temp;
				root->left = &temp_node;
				display(root);
				cout << "value at library root: " << root->value.title << endl; // remove
				cout << "author: " << root->value.author << endl;
				//current_node.left bust become a BookNode with value = val
				return;
			}
			
			else 
			{
				current_node = current_node->left;
				continue;
			}
		}
		
		
		else 
		{
			cout << (current_node->value == val) << endl; // remove
			break;
		}
	}
	
	
	
	
	
}










void Library::check_in(Book val)
{
	if(this->root == nullptr)
	{
		cout << "That book can not be checked in to this library." << endl;
		cout << "There are currently no books in this library." << endl << endl;
		return;
	}
	
	if(search(val) == nullptr)
	{
		cout << "That book can not be checked in to this library." << endl << endl;
		return;
	}
	
	if(this->root->value == val)
	{
		this->root->count++;
	}
	
	if( this->root->value < val)
	{
		BookNode *node = search(val, this->root->right);
		node->count++;
		//search(val, this->root->right)->count++;
	}
	
	else 
	{
		BookNode *node = search(val, this->root->left);
		node->count++;
	}
}











Book* Library::check_out(Book val)
{
	if(this->root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		//cout << "This library does not contain the requested book. (" << val.title << ")" << endl << endl;
		return nullptr;
	}
	
	
}




Book* Library::search(Book val)
{
	cout << "in search (Book val) ... (0)" << endl;
	
	
	if(this->root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return nullptr;
	}
	cout << "in search (Book val) ... (1)" << endl;
	
	display(root);
	cout << (root == nullptr) << endl;
	cout << "root->value.title : " << root->value.title << endl;
	if(this->root->value == val)
	{
		cout << this->root->value.title << endl;
		cout << val.title << endl;
		return &this->root->value;
	}
	
	
	cout << "in search (Book val) ... (2)" << endl;	
	
	
	if(this->root->value < val)
	{
		if((this->root->right == nullptr))
			return nullptr;
		return &search(val, this->root->right)->value;
	}
	cout << "in search (Book val) ... (3)" << endl;
	
	if(this->root->left == nullptr)
	{
		cout << "in search (Book val) ... (4)" << endl; //
		return nullptr;
	}
		
	else 
	{
		return &search(val, this->root->left)->value;
	}

}






Library::BookNode* Library::search(Book val, BookNode *new_root)
{
	if(new_root->value == val)
		return new_root;
	
	if((new_root->left == nullptr) && (new_root->right == nullptr))
		return nullptr;
		
	if(new_root->value < val)
	{
		if(new_root->right == nullptr)
			return nullptr;
		return search(val, new_root->right);
	}
	
	else return search(val, new_root->left);
}














long Library::available_copies(Book val)
{
	cout << "value at library root: " << this->root->value.title << endl; // remove 

	
	cout << "in available copies... (0)" << endl;
	cout << "val.isbn: " << val.isbn << endl;
	cout << "root->value.isbn: " << root->value.isbn << endl;
	cout << "root->value.isbn > val.isbn? : " << (root->value.isbn > val.isbn) << endl;
	
	
	if(this->root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return 0;
	}
	
	cout << "in available_copies... (1)" << endl;
	if(search(val) == nullptr)
	{
		cout << "There are no available copies of this book." << endl;
		cout << "This library does not contain the requested book." << endl << endl;
		return 0;
	}
	
	cout << "in available_copies... (2)" << endl;
	if( this->root->value < val)
	{
		BookNode *node = search(val, this->root->right);
		return node->count;
		//search(val, this->root->right)->count++;
	}
	
	cout << "in available_copies... (3)" << endl;
	if(this->root->value > val)
	{
		BookNode *node = search(val, this->root->left);
		return node->count;
	}
	
	cout << "in available copies... (4)" << endl;
	if(root->value == val)
	{
		cout << "[BOOK FOUND!]" << endl;
		return root->count;
	}
}











#endif //LIBRARY_LIBRARY_H




