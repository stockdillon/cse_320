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







// -----------------------------------------------------------------------

void add(BookNode *&root_node, BookNode *&new_node)
{
	
}

// -----------------------------------------------------------------------














void Library::add(Book val)
{	
	cout << "adding: " << val.title << endl; /////////////////////////////
	
	if(this->root == nullptr)
	{
		/*
		cout << "erferferf" << endl;
		BookNode temp_node(val);
		cout << "@@2223232" << endl;
		BookNode *temp_root = &temp_node;
		cout << "------------" << endl;
		root = &temp_node;
		*/
		BookNode temp_node(val);
		BookNode temp_root
		root = &temp_node;
		////////
		cout << "value at library root: " << root->value.title << endl; // remove 
		//display(this->root);
		////////
		return;
	}
	
	cout << "value at library root: " << root->value.title << endl; // remove
	
	/*
	if(search(val) != nullptr)
	{
		cout << "value at library root: " << root->value.title << endl; ///////
		cout << "This library already contains that book. (" << val.title << ")" << endl;
		return;
	}
	*/
	
	
	cout << "value at library root: " << root->value.title << endl; // remove
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
	if(root == nullptr)
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
	
	if(root->value == val)
	{
		root->count++;
	}
	
	if( root->value < val)
	{
		BookNode *node = search(val, root->right);
		node->count++;
		//search(val, root->right)->count++;
	}
	
	else 
	{
		BookNode *node = search(val, root->left);
		node->count++;
	}
}











Book* Library::check_out(Book val)
{
	if(root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		//cout << "This library does not contain the requested book. (" << val.title << ")" << endl << endl;
		return nullptr;
	}
	
	
}




Book* Library::search(Book val)
{
	cout << "in search (Book val) ... (0)" << endl;
	
	
	if(root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return nullptr;
	}
	cout << "in search (Book val) ... (1)" << endl;
	
	display(root);
	cout << (root == nullptr) << endl;
	cout << "root->value.title : " << root->value.title << endl;
	if(root->value == val)
	{
		cout << root->value.title << endl;
		cout << val.title << endl;
		return &root->value;
	}
	
	
	cout << "in search (Book val) ... (2)" << endl;	
	
	
	if(root->value < val)
	{
		if((root->right == nullptr))
			return nullptr;
		return &search(val, root->right)->value;
	}
	cout << "in search (Book val) ... (3)" << endl;
	
	if(root->left == nullptr)
	{
		cout << "in search (Book val) ... (4)" << endl; //
		return nullptr;
	}
		
	else 
	{
		return &search(val, root->left)->value;
	}

}






Library::BookNode* Library::search(Book val, BookNode *new_root)
{
	if(new_root->value == val)
	{
		cout << "returning original BookNode parameter" << endl;
		return new_root;
	}
	
	if((new_root->left == nullptr) && (new_root->right == nullptr))
	{
		cout << "Book not found, returning nullptr" << endl;
		return nullptr;
	}
		
	if(new_root->value < val)
	{
		cout << "the current node is greater than the desired book (val)" << endl;
		if(new_root->right == nullptr)
		{
			cout << "returning nullptr" << endl;
			return nullptr;
		}
		cout << "recursing... " << endl;
		return search(val, new_root->right);
	}
	
	if(new_root->value > val)
	{
		cout << "the current node is less than the desired book (val)" << endl;
		if(new_root->left == nullptr)
		{
			cout << "returning nullptr" << endl;
			return nullptr;
		}
		cout << "recursing... " << endl;
		return search(val, new_root->left);
	}
	
	/*
	else 
	{
		cout << "recursing... " << endl;
		return search(val, new_root->left);
	}
	*/
}














long Library::available_copies(Book val)
{
	//cout << "(in available_copies) value at library root: " << root->value.title << endl; // remove 

	cout << "in available copies... (0)" << endl;
	cout << "val.title: " << val.title << endl;
	
	
	if(root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return 0;
	}
	
	cout << "in available_copies... (1)" << endl;
	/*
	if(search(val) == nullptr)
	{
		cout << "There are no available copies of this book." << endl;
		cout << "This library does not contain the requested book." << endl << endl;
		return 0;
	}
	*/
	
	if((*root).value == val)
	{
		return (*root).count;
	}
	
	
	cout << "in available_copies... (2)" << endl;
	if( root->value < val)
	{
		if(root->right == nullptr)
		{
			cout << "Desired book was not found in Library." << endl;
			return 0;
		}
		cout << root->right->value.title << endl;
		cout << "11111" << endl;
		BookNode *node = search(val, root->right);
		cout << "22222" << endl;
		return node->count;
		//search(val, root->right)->count++;
	}
	
	cout << "in available_copies... (3)" << endl;
	if(root->value > val)
	{
		if(root->left == nullptr)
		{
			cout << "Desired book was not found in Library" << endl;
			return 0;
		}
		BookNode *node = search(val, root->left);
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




