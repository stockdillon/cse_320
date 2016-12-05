/*

By Dillon Stock
October 23, 2016
Homework 5

*/



#ifndef mystack_h
#define mystack_h

#include <vector>
#include <stdexcept>
using namespace std;

template<class T> class minstack;
template<class T> class myqueue;

// From CSE 331 lecture 6, Onsay (Stacks)
template<typename T>
class MyStack
{
	class underflow_error : runtime_error
	{
	public:
		underflow_error(const char* val2) : runtime_error(val2) {}
	};
	
	private:
		vector<T> vect;
		vector<T> *vect_ptr = &this->vect;
	
	public:
		MyStack();
		// Constructor
		void push(T const & val);
		// Function: pushes an item of type T onto the top of 'vect'
		// Pre: 'vect' is initialized and contains n items
		// Post: 'vect' contains n+1 items with the new item at the top of the stack
		void pop();
		// Function: pops an item of type T from the top of 'vect'
		// Pre: 'vect' is initialized and contains n items
		// Post: 'vect' contains n-1 items
		void display();
		// Function: displays the contents of 'vect' from the bottom up
		// Pre: 'vect' is initialized
		// Post: 'vect' is unchanged; the stack remains the same
		T GetTop();
		// Function: returns the top item in 'vect' that contains the contents of the stack
		// Pre: 'vect' is intialized and contains at least 1 item
		// Post: 'vect' is unchanged, the stack remains the same
		bool empty();
		// Function: returns true if there are 0 items in 'vect', false if there are > 0 items in 'vect'
		// Pre: 'vect' is initialized
		// Post: 'vect' is unchanged, the stack remains the same
	
	friend class minstack<T>;
	friend class myqueue<T>; ////////
};


template<typename T>
MyStack<T>::MyStack()
{
}




template<typename T>
void MyStack<T>::push(T const & val)
{
	this->vect.push_back(val);
}




template<typename T>
void MyStack<T>::pop()
{
	if(empty())
	{
		throw MyStack::underflow_error("Stack Underflow");
	}
	
	else vect.pop_back();
}






template<typename T>
void MyStack<T>::display()
{
	for(unsigned i = 0; i < vect.size(); i++)
	{
		cout << "Top is --> " << vect[i] << endl;
	}
}





template<typename T>
T MyStack<T>::GetTop()
{	
	if(empty())
	{
		throw MyStack::underflow_error("Stack Underflow");
	}
	
	else return this->vect[this->vect.size() - 1];
}





template<typename T>
bool MyStack<T>::empty()
{
	return(vect.size() == 0);
}



#endif /* mystack_h */

