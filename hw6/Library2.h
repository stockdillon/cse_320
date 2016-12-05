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
  bool operator==(const Book &other) { return isbn == other.isbn; };
  bool operator!=(const Book &other) { return isbn != other.isbn; };

};

class Library {
 public:
 
  // Constructor; sets root = nullptr
  Library();
  
  // Function: Creates a new BookNode using the Book parameter as its value, calls private add function
  // Pre: 'Library' is initialized with n number of BookNodes
  // Post: 'Library' contains n+1 BookNodes 
  void add(Book);
  
  // Function: Increments the count of a BookNode which has a value equal to the Book parameter
  // Pre: 'Library' is initialized; A BookNode exists which has a value equal to the Book parameter
  // Post: Count has been incremented by one for a particular BookNode
  void check_in(Book);
  
  // Function: Decrements the count of a BookNode which has a value equal to the Book parameter
  // Pre: 'Library' is initialize; A BookNode exists which has a value equal to the Book parameter
  // Post: Count has been decremented by one for a particular BookNode
  Book *check_out(Book);
  
  // Function: Calls the private, 2 parameter search function, then returns a ptr to the Book contained
  //			within the BookNode that private search function returns.
  // Pre: 'Library' is initialized
  // Post: 'Library' is unchanged
  Book *search(Book);
  
  // Function: Calls search function to retrieve the address of a BookNode containing the desired book;
  //			returns the member variable 'count' of that BookNode
  // Pre: 'Library' is initialized
  // Post: 'Library' is unchanged
  long available_copies(Book);  
  
  // Function: Calls the private display function, which displays every BookNode in the current Library
  // Pre: 'Library' is initialized
  // Post: 'Library' is unchanged
  //void display_public(); //*************


 private:
  struct BookNode {
    Book value;
    BookNode *left;
    BookNode *right;
    size_t count = 1;
    BookNode(Book b) : value(b), left(nullptr), right(nullptr) {};
  };
  BookNode *root;
  
  
  // Function: If 'Library' is empty, root will point to the new BookNode created in the public add function;
  //			else, this function calls itself (recursion) until an appropriate BookNode is found
  //			with a nullptr as either its right or left member variable depending on the new BookNode
  // Pre: 'Library' is initialized with n number of nodes
  // Post: If 'Library' was previosly empty, it now contains a single BookNode at the root. Otherwise
  //		'Library' now contains n+1 nodes
  void add(BookNode *&root_node, BookNode *&new_node);
  
  
  // Function: Returns a nullptr if the Book is not contained in any BookNode within the library
  //			else, returns a ptr to the BookNode that contains the desired Book
  // Pre: 'Library' is initialized
  // Post: 'Library' is unchanged 
  BookNode *search(Book, BookNode *root);
  
  // Function: Displays the member variables of every BookNode contained in the Library
  // Pre: 'Library' is initialized
  // Post: 'Library' is unchanged 
  //void display(BookNode *current_node); //*************
};



/*
void Library::display_public()
{
	display(this->root);
}


void Library::display(BookNode *current_node)
{
	//cout << "... Displaying contents of Library..." << endl;
	
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


*/




Library::Library()
{
	this->root = nullptr;
}







void Library::add(BookNode *&root_node, BookNode *&new_node)
{
	//cout << "inside 2 parameter add function " << endl; // remove 
	
	if((root_node == nullptr))
	{
		//cout << "root_node was empty... " << endl; // remove
		root_node = new_node;
		return;
	}
	
	
	if(new_node->value < root_node->value)
	{
		//cout << "new node is LESS than root_node" << endl; // remove
		if(root_node->left == nullptr)
		{
			//cout << "found nullptr, adding node." << endl; // remove
			root_node->left = new_node;
		}
		else 
		{
			//cout << "new node is less, recursing.. " << endl; // remove
			add(root_node->left, new_node);
		}
	}
	
	
	if(root_node->value < new_node->value)
	{
		//cout << "new node is GREATER than root_node" << endl; // remove
		if(root_node->right == nullptr) 
		{
			//cout << "found nullptr, adding node." << endl; // remove
			root_node->right = new_node;
		}
		else 
		{
			//cout << "new node is greater, recursing..." << endl; // remove
			add(root_node->right, new_node);
		}
	}
	
}







void Library::add(Book val)
{
	//cout << endl << "adding: " << val.title << endl << endl;
	
	BookNode *new_booknode;
	new_booknode = new BookNode(val);
	add( root, new_booknode );
	
	
	//display(); 
	///////////	
	/*
	if(root != nullptr)
	{
		cout << endl << "Current root: " << endl;
		cout << "isbn: " << root->value.isbn << endl;
		cout << "title: " << root->value.title << endl;
		cout << "author: " << root->value.author << endl << endl;
	}
	*/
	///////////
}







void Library::check_in(Book val)
{
	if(root == nullptr)
	{
		cout << "That book can not be checked in to this library." << endl;
		cout << "There are currently no books in this library." << endl << endl;
		return;
	}
	
	if(root->value == val)
	{
		root->count++;
		return;
	}
	
	
	
	if( root->value < val)
	{
		if(search(val, root->right) != nullptr)
		{
			search(val, root->right)->count++;
			return;
		}
		
		else 
		{
			cout << "That book can not be checked in to this library." << endl;
			return;
		}
	}
	
	if( val < root->value)
	{
		if(search(val, root->left) != nullptr)
		{
			search(val, root->left)->count++;
			return;
		}
		
		else 
		{
			cout << "That book can not be checked in to this library." << endl;
			return;
		}
	}
}







Book* Library::check_out(Book val)
{	
	if(root == nullptr)
	{
		cout << "That book can not be checked out of this library." << endl;
		cout << "There are currently no books in this library." << endl << endl;
		return nullptr;
	}
	
	
	if(root->value == val)
	{
		root->count--;
		return &(root->value);
	}
	
	
	if( root->value < val)
	{
		if(search(val, root->right) != nullptr)
		{
			search(val, root->right)->count--;
			return &(search(val, root->right)->value);
		}
		
		else 
		{
			cout << "That book can not be checked in to this library." << endl;
			return nullptr;
		}
	}
	
	
	if( val < root->value)
	{
		if(search(val, root->left) != nullptr)
		{
			search(val, root->left)->count--;
			return &(search(val, root->left)->value);
		}
		
		else 
		{
			cout << "That book can not be checked in to this library." << endl;
			return nullptr;
		}
	}
}




Book* Library::search(Book val)
{	
	if(root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return nullptr;
	}
		
	//display();
	if(root->value == val)
	{
		return &root->value;
	}
		
	
	if(root->value < val)
	{
		if((root->right == nullptr))
		{
			return nullptr;
		}
		else if (search(val, root->right) != nullptr)
		{
			return &(search(val, root->right)->value);
		}
		else return nullptr;
	}	
	
	
	if(val < root->value)
	{
		if((root->left == nullptr))
		{
			return nullptr;
		}
		else if (search(val, root->left) != nullptr)
		{
			return &(search(val, root->left)->value);
		}
		else return nullptr;
	}
	
}






Library::BookNode* Library::search(Book val, BookNode *new_root)
{
	if(new_root->value == val)
	{
		//cout << "returning original BookNode parameter" << endl;
		return new_root;
	}
	
	if((new_root->left == nullptr) && (new_root->right == nullptr))
	{
		cout << "Book not found, returning nullptr" << endl;
		return nullptr;
	}
		
	if(val < new_root->value)
	{
		//cout << "the current node is greater than the desired book (val)" << endl;
		if(new_root->left == nullptr)
		{
			//cout << "returning nullptr" << endl;
			return nullptr;
		}
		return search(val, new_root->left);
	}
	
	if(new_root->value < val)
	{
		//cout << "the current node is less than the desired book (val)" << endl;
		if(new_root->right == nullptr)
		{
			//cout << "returning nullptr" << endl;
			return nullptr;
		}
		return search(val, new_root->right);
	}
	
}







long Library::available_copies(Book val)
{
	
	if(root == nullptr)
	{
		cout << "There are currently no books in this library." << endl << endl;
		return -1;
	}
	
	
	if(root->value == val)
	{
		return root->count;
	}
	
	
	if( root->value < val)
	{
		if(root->right == nullptr)
		{
			cout << "Desired book was not found in Library." << endl;
			return -1;
		}

		if(search(val, root->right) != nullptr)
		{
			return search(val, root->right)->count;
		}
	}
	
	if(val < root->value)
	{
		if(root->left == nullptr)
		{
			cout << "Desired book was not found in Library" << endl;
			return -1;
		}

		if(search(val, root->left) != nullptr)
		{
			return search(val, root->left)->count;
		}
	}
	
}



#endif //LIBRARY_LIBRARY_H




