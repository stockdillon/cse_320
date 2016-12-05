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
		display(current_node->left);
	}
	
	if ( current_node->right != nullptr)
	{
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
	if(this->root == nullptr)
	{
		BookNode node = BookNode(val);
		this->root = &node;
		////////
		cout << "value at library root: " << this->root->value.title << endl;
		display(this->root);
		////////
		return;
	}
	
	/*
	if(search(val) != nullptr)
	{
		cout << "value at library root: " << this->root->value.title << endl; ///////
		cout << "This library already contains that book. (" << val.title << ")" << endl;
		return;
	}
	*/
	
	BookNode node = BookNode(val);
	
	BookNode *current_node = this->root;
	while(true)
	{
		if(current_node->value < val)
		{
			if(current_node->right == nullptr)
			{
				current_node->right = &node;
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
			if(current_node->left == nullptr)
			{
				current_node->left == &node;
				cout << "Hamlet->left became MacBeth" << endl;
				return;
			}
			else 
			{
				current_node = current_node->left;
				continue;
			}
		}
		
		else break;
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
	if(this->root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return nullptr;
	}
	cout << "check 1" << endl;
	
	
	if(this->root->value == val)
	{
		cout << this->root->value.title << endl;
		cout << val.title << endl;
		return &this->root->value;
	}
	
	
	cout << "check 2" << endl;	
	
	
	if(this->root->value < val)
	{
		if((this->root->right == nullptr))
			return nullptr;
		return &search(val, this->root->right)->value;
	}
	cout << "check 3" << endl;
	
	if(this->root->left == nullptr)
	{
		cout << "check 4" << endl; //
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
	if(this->root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return 0;
	}
	if(search(val) == nullptr)
	{
		cout << "There are no available copies of this book." << endl;
		cout << "This library does not contain the requested book." << endl << endl;
		return 0;
	}
	
	if( this->root->value < val)
	{
		BookNode *node = search(val, this->root->right);
		return node->count;
		//search(val, this->root->right)->count++;
	}
	
	else 
	{
		BookNode *node = search(val, this->root->left);
		return node->count;
	}
}











#endif //LIBRARY_LIBRARY_H
