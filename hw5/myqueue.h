/*

By Dillon Stock
October 23, 2016
Homework 5

*/

#ifndef myqueue_h
#define myqueue_h


#include <vector>
#include <stdexcept>
using namespace std;


template<class T> class MyStack;
template<class T> class minstack;

// From CSE 331 lecture 7, Onsay (Queues)
template<typename T>
class myqueue
{
	private:
		MyStack<T> stack;
		MyStack<T> temp_stack;
	
	public:
		myqueue();
		// Constructor
		void push(T val);
		// Function: pushes an item of type T onto the bottom of stack.vect.
		// Pre: stack is initialized and 'vect' contains n items.
		// Post: 'vect' contains n+1 items with the new item at the bottom of the stack.
		void pop();
		// Function: pops an item of type T from the top of stack.vect.
		// Pre: stack is initialized and 'vect' contains n>0 items.
		// Post: 'vect' contains n-1 items.
		T gettop();
		// Function: returns the top item in 'this->fullstack.vect' 
		// Pre: stack is intialized and contains at least 1 item.
		// Post: this->vect and fullstack.vect are unchanged, the stacks remain the same
		bool empty();
		// Function: returns true if there are 0 items in 'vect', false if there are > 0 items in 'vect'.
		// Pre: stack is initialized
		// Post: this->vect and fullstack.vect are unchanged, the stacks remain the same
		
	friend class MyStack<T>;
	friend class minstack<T>;	
};






template<typename T>
myqueue<T>::myqueue()
{
}





template<typename T>
void myqueue<T>::push(T val)
{
	stack.push(val);
}




template<typename T>
void myqueue<T>::pop()
{
	if(!empty())
	{
		for(unsigned i = 1; i < stack.vect.size(); i++)
		{
			temp_stack.push(stack.vect[i]);
		}
		
		stack.vect = temp_stack.vect;
		temp_stack.vect.clear();
	}
	else throw typename MyStack<T>::underflow_error("Stack Underflow");
}




template<typename T>
T myqueue<T>::gettop()
{
	if(!empty())
	{
		return stack.vect[0];
	}
	
	else throw typename MyStack<T>::underflow_error("Stack Underflow");
}





template<typename T>
bool myqueue<T>::empty()
{
	return(stack.vect.size() == 0);
}





# endif /*myqueue_h*/
 
