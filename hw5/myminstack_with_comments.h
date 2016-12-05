 

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
		unsigned size_ = 0;
		MyStack<T> fullstack;
		T min;
		vector<T> vect;
		vector<T> *vect_ptr = &this->vect;
		
	
	public:
		minstack();
		void push(T const & val);
		void pop();
		void display();
		T gettop();
		T getMin();
		bool empty();
		
		
	friend class MyStack<T>;
		
};



template<typename T>
minstack<T>::minstack()
{	
}


// Done
template<typename T>
void minstack<T>::push(T const & val)
{
	/*
	cout << endl << endl << "Before Push..... " << endl;
	cout << "Full stack size: " << this->fullstack.vect.size() << endl << "Min Stack Size: " << vect.size() << endl;
	cout << "Trying to push... val = " << val << endl;

	if(!empty())
	{
		cout << "Current top of Min Stack: " << vect[vect.size() -1] << endl;
		cout << "Current top of Full Stack: " << this->fullstack.vect[this->fullstack.vect.size() - 1] << endl;
	}
	*/
	
	
	if(this->size_ == 0)
	{
		this->min = val;
	}
	
	this->fullstack.push(val);
	
	if(val <= this->min)
	{
		this->size_++;
		this->vect.push_back(val);
		this->min = val;	
	}
	
	
	/*
	cout << "After Push..... " << endl;
	cout << "Full stack size: " << this->fullstack.vect.size() << endl << "Min Stack Size: " << vect.size() << endl;
		
	if(!empty())
	{
		cout << "Current top of Min Stack: " << vect[vect.size() -1] << endl;
		cout << "Current top of Full Stack: " << this->fullstack.vect[this->fullstack.vect.size() - 1] << endl;
	}
	*/
	
}



template<typename T>
void minstack<T>::pop()
{
	/*
	cout << endl << endl << "Before Pop..... " << endl;
	cout << "Full stack size: " << this->fullstack.vect.size() << endl << "Min Stack Size: " << vect.size() << endl;

	if(!empty())
	{
		cout << "Current top of Min Stack: " << vect[vect.size() -1] << endl;
		cout << "Current top of Full Stack: " << this->fullstack.vect[this->fullstack.vect.size() - 1] << endl;
	}
	*/
	
	
	if(empty())
	{
		throw std::out_of_range("Stack Underflow");
		return;
	}	
	
	
	//cout << "Top item on the MinStack: " << this->getMin() << endl << "Top item on the Full Stack: " << this->fullstack.GetTop() << endl << endl;
	//if(this->getMin() == this->fullstack.vect[this->fullstack.vect.size() - 1])
	if( getMin() == this->fullstack.GetTop())
	//if(vect[vect.size() - 1] == min_vect[min_vect.size() - 1])
	{
		vect.pop_back();
		this->size_--;
	}
	
	
	if(!empty())
	{
		this->fullstack.pop();
	}
	
		
		
	
	
	//cout << endl << endl << "After Pop..... " << endl;
	//cout << "Full stack size: " << this->fullstack.vect.size() << endl << "Min Stack Size: " << vect.size() << endl;
	
	/*
	if(!empty())
	{
		cout << "Current top of Min Stack: " << vect[vect.size() -1] << endl;
		cout << "Current top of Full Stack: " << this->fullstack.vect[this->fullstack.vect.size() - 1] << endl << endl;
	}	
	*/
	
}


/*
template<typename T>
void minstack<T>::display()
{
	for(unsigned i = 0; i < this->size_; i++)
	{
		cout << this->vect[i] << endl;
	}
}
*/




template<typename T>
T minstack<T>::getMin()
{
	if(empty())
	{
		throw std::underflow_error("Stack Underflow");
	}
	
	return vect[vect.size() - 1];
}


template<typename T>
T minstack<T>::gettop()
{
	if(empty())
	{
		throw std::underflow_error("Stack Underflow");
	}
	
	else return this->fullstack.GetTop();
}


// Done
template<typename T>
bool minstack<T>::empty()
{
	return(this->fullstack.vect.size() == 0);
	//return(this->fullstack.empty());
}




# endif /* my min stack*/
