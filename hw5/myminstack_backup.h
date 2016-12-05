 

#ifndef myminstack_h
#define myminstack_h


#include <vector>
#include <stdexcept>
using namespace std;

// From lecture 6 (Stacks)
// Declare templated class with private and public members
template<typename T>
class minstack
{
	private:
		unsigned size = 0;
		
		MyStack<T> stack_of_min;
		T min;
		vector<T> vect;
		vector<T> *vect_ptr = &this->vect;
		
		vector<T> min_vect;
		vector<T> min_vect_ptr;
		
	
	public:
		minstack();
		void push(T const & val);
		void pop();
		void display();
		T gettop();
		T getMin();
		bool empty();
		
		
	//friend class Mystack;
		
};



template<typename T>
minstack<T>::minstack()
{	
}


// Done
template<typename T>
void minstack<T>::push(T const & val)
{
	if(this->size == 0)
	{
		this->min = val;
	}
	
	this->size++;
	this->vect.push_back(val);
	cout << "PUSHED MAIN STACK : " << val << endl;

	
	
	if(val <= this->min)
	{
		this->stack_of_min.push(val);
		cout << "PUSHED MIN: " << val << endl;
		this->min = val;
	}
	
}



template<typename T>
void minstack<T>::pop()
{
	if(empty())
	{
		throw std::out_of_range("Stack Underflow");
	}	

	this->size--;
	
	cout << "gettop()" << this->gettop() << endl << "this->stack_of_min.GetTop()" << this->stack_of_min.GetTop() << endl << endl;
	if(this->gettop() == this->stack_of_min.GetTop())
	{
		cout << "removing from min stack" << endl;
		this->stack_of_min.pop();
		this->min = this->stack_of_min.GetTop();
	}
	
	this->vect.pop_back();
	cout << "POP" << endl;
}



template<typename T>
void minstack<T>::display()
{
	for(unsigned i = 0; i < this->size; i++)
	{
		cout << this->vect[i] << endl;
	}
}





template<typename T>
T minstack<T>::getMin()
{
	return this->min;
}


template<typename T>
T minstack<T>::gettop()
{
	
	cout << "The size of stack: " << this->size << endl << "stack[size - 1] : " << this->vect[this->size -1 ] << endl << endl;
	if(empty())
	{
		throw std::out_of_range("Stack Underflow");
	}
	
	else return this->vect[this->size - 1];
}


// Done
template<typename T>
bool minstack<T>::empty()
{
	return(this->size == 0);
}















# endif /* my min stack*/
