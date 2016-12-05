/*

By Dillon Stock
October 23, 2016
Homework 5

*/

#ifndef myminstack_h
#define myminstack_h


#include <vector>
#include <stdexcept>
using namespace std;

template<class T> class MyStack;
template<class T> class myqueue;

// From CSE 331 lecture 6, Onsay (Stacks)
template<typename T>
class minstack
{
	private:
		MyStack<T> fullstack;
		T min;
		vector<T> vect;
		vector<T> *vect_ptr = &this->vect;
		
	public:
		minstack();
		void push(T const & val);
		// Function: pushes an item of type T onto the top of fullstack.vect.
		//		If parameter 'val' is less than top item of this->vect,
		//		then 'val' is also pushed to this->vect.
		// Pre: stack is initialized and fullstack.vect contains n items.
		//		this->vect contains k items.
		// Post: fullstack.vect contains n+1 items with the new item at the top of the stack.
		//		this->vect contains either k or k+1 items, depending on data in stack.
		void pop();
		// Function: pops an item of type T from the top of 'vect'
		// 		if top item is equal to the top item in fullstack, fullstack top is also popped
		// Pre: stack is initialized and fullstack.vect contains n items.
		//		this->vect contains k items.
		// Post: fullstack.vect contains n-1 items.
		//		this->vect contains either k or k-1 items, depending on data in stack.
		T gettop();
		// Function: returns the top item in 'this->fullstack.vect' 
		// Pre: stack is intialized and contains at least 1 item.
		// Post: this->vect and fullstack.vect are unchanged, the stacks remain the same
		T getMin();
		// Function: returns the top item in this->vect, (the minimum item in fullstack.vect).
		// Pre: 'vect' is intialized and contains at least 1 item
		// Post: this->vect and fullstack.vect are unchanged, the stacks remain the same
		bool empty();
		// Function: returns true if there are 0 items in 'vect', false if there are > 0 items in this->vect.
		// Pre: stack is initialized
		// Post: this->vect and fullstack.vect are unchanged, the stacks remain the same

			
	friend class MyStack<T>;	
};





template<typename T>
minstack<T>::minstack()
{	
}





template<typename T>
void minstack<T>::push(T const & val)
{	
	if(empty())
	{
		min = val;
	}
	
	this->fullstack.push(val);
	
	if(val <= this->min)
	{
		this->vect.push_back(val);
		this->min = val;	
	}
}



template<typename T>
void minstack<T>::pop()
{
	if(empty())
	{
		throw typename MyStack<T>::underflow_error("Stack Underflow");
		return;
	}	
	
	if( getMin() == this->fullstack.GetTop())
	{
		vect.pop_back();
	}
	
	if(!empty())
	{
		this->fullstack.pop();
	}
}




template<typename T>
T minstack<T>::getMin()
{
	if(empty())
	{
		throw typename MyStack<T>::underflow_error("Stack Underflow");
	}
	
	return vect[vect.size() - 1];
}





template<typename T>
T minstack<T>::gettop()
{
	if(empty())
	{
		throw typename MyStack<T>::underflow_error("Stack Underflow");
	}
	
	else return this->fullstack.GetTop();
}




template<typename T>
bool minstack<T>::empty()
{
	return(this->fullstack.vect.size() == 0);
}


# endif /* my min stack*/
