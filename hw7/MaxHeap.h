/* 
 * File:   MaxHeap.h
 * Author: onsayse
 *
 * Created on November 2, 2016, 5:03 PM
 */

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath> 
#include <algorithm> //
using namespace std;
template <typename T>
class myMaxHeap 
{	
private:
	long currentsize;
	vector<T> data;
	
	// Function: Swaps the value at a given index with the larger of its two children; 
	//			 continues to call itself recursively until the value at the 
	//			 current index is greater than both of its children
	// Pre: 'MaxHeap' is initialized
	// Post: 'MaxHeap' size is unchanged, the value which was previously located at 'hole' index
	// 		 is now in its correct location within the member vector 'data'
	void percolateDown(int hole);
	
	// Function: Called when a new node is added to MaxHeap; 
	//			 swaps the new node with its parent node
	//			 until a parent node with a greater value is found
	// Pre: 'MaxHeap' is initialized, the most recently added node 
	//		may or may not be in its correct position
	// Post: The most recently added node is in its correct position
	void percolateUp(int hole);
	
	// Function: Called within the MaxHeap constructor; 
	//			 starting at index (currentsize/2), and ending at index 0,
	//			 this function percolates each value down until it reaches its correct position
	// Pre: 'MaxHeap' is initialized, data vector has not been properly arranged
	// Post: Each node is greater than or equal to each of its children
	void heapCreate();


public:
	// Function: Returns true if the currentsize member variable is 0; 
	//			 false if any nodes are contained in MaxHeap
	// Pre: 'MaxHeap' is initialized
	// Post: 'MaxHeap' is unchanged, currentsize remains the same
	bool isEmpty() const;
	
	// Function: Returns the value at data[index] 
	// Pre: 'MaxHeap' is initialized,
	// Post: 'MaxHeap' is unchanged, currentsize remains the same
	const T getItem(int index);
	
	// Function: Prints the member vector 'data' from index 0 to 
	//			 index (currentsize - 1), the contents of the heap
	// Pre: 'MaxHeap' is initialized
	// Post: 'MaxHeap' is unchanged, currentsize remains the same
	void display();
	
	// Function: Returns the height of the heap, by starting at the last node and working back
	//			 to the first node, incrementing as each parent node is found
	// Pre: 'MaxHeap' is initialized
	// Post: 'MaxHeap' is unchanged, currentsize remains the same
	int getHeight() const;
	
	// Function: Returns currentsize, the number of nodes in the heap
	// Pre: 'MaxHeap' is initialized
	// Post: 'MaxHeap' is unchanged, currentsize remains the same
	int getNumberOfNodes() const;
	
	// Function: Clears the member vector 'data'
	// Pre: 'MaxHeap' is initialized
	// Post: Member vector 'data' is empty, currentsize is 0, MaxHeap contains no nodes
	void clear();
	
	// Function: Returns the value at index 0 of member vector 'data' 
	// Pre: 'MaxHeap' is initialized
	// Post: 'MaxHeap' is unchanged, currentsize remains the same
	T peekTop() const;
	
	// Function: Adds a new node the the heap, calls percolate up on that item 
	//			 until correct position is reached
	// Pre: 'MaxHeap' is initialized, contains n number of nodes
	// Post: 'MaxHeap' contains n + 1 number of nodes
	void add(const T& newData);

	// Function: Simply pops one item from 'data' 
	// Pre: 'MaxHeap' is initialized, with n number of nodes
	// Post: 'MaxHeap' contains n-1 number of nodes
	void remove();

	// Function: Adds parameter positiveValue to the value at data[p], 
	//			 then calls percolateUp until the new
	//			 value at data[p] is in its correct position 
	//			 (children nodes are less, parent node is greater)
	// Pre: 'MaxHeap' is initialized
	// Post: One value within the heap has been changed and then moved to its correct position
	void increaseKey(int p, T positiveValue);

	// Function: Subtracts parameter positiveValue from the value at data[p], 
	//			 then calls percolateDown until the new
	//			 value at data[p] is in its correct position 
	//			 (children nodes are less, parent node is greater)
	// Pre: 'MaxHeap' is initialized
	// Post: One value within the heap has been changed and then moved to its correct position
	void decreaseKey(int p, T positiveValue);

	// Function: Constructor; sets currentsize = 0, calls heapCreate function to properly arrange
	// 			 the values within member vector 'data'
	// Pre: 'MaxHeap' has not been initialized
	// Post: 'MaxHeap' is initialized and the children nodes of any given node are 
	//		  less than the node itself
	myMaxHeap(vector<T> &input);



   //Exceptions HeapOverflow and HeapUnderflow go here...
	class underflow_error : runtime_error
	{
	public:
		underflow_error(const char* val2) : runtime_error(val2) {}
	};	

};
#endif /* MAXHEAP_H */



template<typename T>
void myMaxHeap<T>::percolateDown(int hole)
{
	/*
	cout << "percolating down... " << endl; //
	cout << "current index is: " << hole << endl;
	cout << "current value at this index is..." << data[hole] << endl;
	if((hole*2) + 1 < currentsize)
	{
		cout << "left child: " << data[(hole*2) + 1] << endl;
	}
	
	if((hole*2) + 2 < currentsize)
	{
		cout << "right child: " << data[(hole*2) + 2] << endl;
	}
	cout << endl;
	*/
	
	
	
	
	unsigned i = hole;
	
	if(((2*i) + 1) > currentsize) return;
	if((data[(2*i)+1] > data[(2*i)+2]) && (data[(2*i)+1] > data[i]))
	{
		//cout << "swapping " << data[i] << " for " << data[(2*i) + 1] << endl; // keep
		iter_swap(data.begin() + i, data.begin() + (2*i)+1); // 
		int new_hole = (2*i) + 1;
		percolateDown(new_hole);
	}
	
	else if (data[(2*i)+1] < data[(2*i)+2] && (((2*i) + 2) < currentsize) && (data[(2*i)+2] > data[i]))
	{
		//cout << "swapping " << data[i] << " for " << data[(2*i) + 2] << endl; // keep
		iter_swap(data.begin() + i, data.begin() + (2*i)+2); // 
		i = (2*i) + 2;
		percolateDown(i);
	}

}



template<typename T>
void myMaxHeap<T>::percolateUp(int hole)
{
	if(hole == 0) return;
	unsigned i = hole;
	if(data[i] > data[(i-1)/2])
	{
		iter_swap(data.begin() + i, data.begin() + (i-1)/2); // 
		i = (i-1)/2;
		percolateUp(i);
	}
}



template<typename T>
void myMaxHeap<T>::heapCreate()
{
	for(int i = (data.size()/2); i >= 0; i--)
	{
		percolateDown(i);
	}
}


template<typename T>
bool myMaxHeap<T>::isEmpty() const
{
	return(currentsize == 0);
}



template<typename T>
const T myMaxHeap<T>::getItem(int index)
{
	if(currentsize == 0)
	{
		throw myMaxHeap::underflow_error("Stack Underflow");
	}
	
	return( data[index]);
}



template<typename T>
void myMaxHeap<T>::display()
{
	if(currentsize == 0)
	{
		throw myMaxHeap::underflow_error("Stack Underflow");
	}
	
	
	for(unsigned i = 0; i < currentsize; i++)
	{
		cout << data[i] << endl;
	}
}





template<typename T>
int myMaxHeap<T>::getHeight() const
{
	int count = 0;
	int n = currentsize - 1;
	while (n > 0)
	{
		count++;
		n = ((n-1)/2);
	}
	return count;
}





template<typename T>
int myMaxHeap<T>::getNumberOfNodes() const
{
	return(currentsize );
}



template<typename T>
void myMaxHeap<T>::clear()
{
	data.clear();
	currentsize = 0;
}



template<typename T>
T myMaxHeap<T>::peekTop() const
{
	if(currentsize == 0)
	{
		throw myMaxHeap::underflow_error("Stack Underflow");
	}
	
	return data[0];
}



template<typename T>
void myMaxHeap<T>::add(const T& newData)
{
	/*
	for(unsigned i = 0; i < currentsize; i++)
	{
		if(data[i] == newData)
		{
			cout << "Duplicate... could not add" << endl;
			return;
		}
	}
	*/
	data.push_back(newData);
	currentsize++;
	percolateUp(currentsize - 1);
}


/*
template<typename T>
void myMaxHeap<T>::remove()
{
	if(data.size() != 1)
	{
		percolateDown(0);
	}
}
*/



template<typename T>
void myMaxHeap<T>::remove()
{
	if(currentsize == 0)
	{
		throw myMaxHeap::underflow_error("Stack Underflow");
	}
	
	if(currentsize > 0)
	{
		data[0] = data[currentsize - 1];
		currentsize--;
		percolateDown(0);
	}
	
	
	
	return;
}



template<typename T>
void myMaxHeap<T>::increaseKey(int p, T positiveValue)
{
	if(currentsize == 0)
	{
		throw myMaxHeap::underflow_error("Stack Underflow");
	}

	data[p-1] = data[p-1] + positiveValue;
	percolateUp(p-1);
}



template<typename T>
void myMaxHeap<T>::decreaseKey(int p, T positiveValue)
{
	if(currentsize == 0)
	{
		throw myMaxHeap::underflow_error("Stack Underflow");
	}
	
	data[p-1] = data[p-1] - positiveValue;
	percolateDown(p-1);
}




template<typename T>
myMaxHeap<T>::myMaxHeap(vector<T> &input)
{
	/*
	int test;
	vector<T> no_duplicates;
	no_duplicates.push_back(input[0]);
	for(unsigned i = 1; i < input.size() ; i++)
	{
		test = 0;
		
		for(unsigned j = 0; j < i; j++)
		{
			if(input[j] == input[i])
			{
				test = 1;
			}
		}
			
		if(test == 0)
		{
			no_duplicates.push_back(input[i]);
		}
	}
	
	
	currentsize = no_duplicates.size();
	//data = new vector<T>;
	data.push_back(no_duplicates[0]);
	for(unsigned i = 1; i < currentsize; i++)
	{
		data.push_back(no_duplicates[i]);
		if(data[i] > data[(i-1)/2])
		{
			percolateUp(i);
		}
	}
	*/
	
	
	/////////////////////
	currentsize = 0;
	for(unsigned i = 0; i < input.size(); i++)
	{
		data.push_back(input[i]);
		currentsize++;
	}
	//cout << "data.size() : " << data.size() << endl;
	heapCreate();
	/////////////////////
	
}


















