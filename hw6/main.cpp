//
// Created by Scott Swarthout on 10/4/16.
//
#include <iostream>
#include "Library.h"
using namespace std;

int main() {
	
  Library library;
  
  Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
  Book macbeth("978-0743477109", "MacBeth", "The Bard");
  Book book1("978-0743477124", "Book 1", "Big D");
  Book book2("978-0743477108", "Book 2", "Big D");
  Book book3("978-0743477120", "Book 3", "Big D");
    
  cout << endl;
  
  cout << "Hamlet" << endl;
  cout << "isbn: " << hamlet.isbn << endl;
  cout << "title: " << hamlet.title << endl;
  cout << "author: " << hamlet.author << endl << endl;
  
  cout << "MacBeth" << endl;
  cout << "isbn: " << macbeth.isbn << endl;
  cout << "title: " << macbeth.title << endl;
  cout << "author: " << macbeth.author << endl << endl;
  
  //fputs(hamlet > macbeth ? "Hamlet > MacBeth \n\n" : "Hamlet < MacBeth \n\n", stdout);
 

  library.add(hamlet);  
  library.add(macbeth); 
  library.add(book1);
  library.add(book2);
  library.add(book3);
  
  //library.display_public();

  auto num_left = library.available_copies(hamlet);
  
  cout << "Number of copies (Hamlet): " << num_left << endl;

  auto found = library.search(hamlet);
  cout << "Found book: " << found->isbn << found->author << endl;
  auto checked_out = library.check_out(*found);

  num_left = library.available_copies(hamlet);
  cout << "Checked out book: " << checked_out->isbn << checked_out->author << endl;
  cout << "Number of copies (Hamlet): " << num_left << endl;

  library.check_in(*checked_out);
  num_left = library.available_copies(hamlet);
  cout << "Number of copies (Hamlet): " << num_left << endl;
  
  
  cout << endl << endl;
  found = library.search(book3);
  cout << "Found book: " << found->isbn << found->author << endl;
  checked_out = library.check_out(*found);
  library.check_in(*checked_out);
  library.check_in(*checked_out);
  num_left = library.available_copies(book3);
  cout << "Number of copies (Book 3): " << num_left << endl;
  
  


}

