/*
 * SearchSort2.h
 *
 *  Created on: September 25th, 2016
 *  Author: Dillon Stock
 *  Homework 3
 *  Due: September 29th
 */

#ifndef SEARCHSORT2_H_
#define SEARCHSORT2_H_
#include <iostream>
#include <vector>


using namespace std;

// REMOVE ----
template <typename Comparable>
void simpleprint(vector<Comparable> &A)
{
	for(unsigned i = 0; i < A.size(); i++)
	{
		
		cout << "items[" << i << "]:  " << A[i] << endl;
	}
}


// Insertion sort
template <typename Comparable>
void insertion_sort(vector<Comparable> &A)
{
	unsigned size = A.size();
	for(unsigned i=1; i < size; i++)
	{
		unsigned key = A[i];
		//insert A[j] into sorted array A[1...i-1]
		int j = i-1;
		while ((j >= 0) && (A[j] > key))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}





// ---- REMOVE 



template <typename Comparable>
int binarySearch(vector<Comparable> &items, const int key)
{
	
	insertion_sort(items);
	
	if((key < items[0]) || (key > items[items.size()-1]))
	{
		return -1;
	}
	
	int even_odd = 2;
	int middle;
	int index = 0;
	
	vector<Comparable> items2;
	typename std::vector<Comparable>::iterator it = items2.begin();
	items2.insert(it, items.begin(), items.begin() + items.size());
	
	while(items2.size() > 0)
	{
		if((items2.size() == 1) && (items2[0] != key))
		{
			return -1;
		}
		
		even_odd = 2;
		
		if (items2.size() % 2 == 1)
		{
			even_odd = 1;
		}
		
		middle = ((items2.size() - even_odd)/2);
		
		if (items2[middle] == key)
		{
			return (index + middle);
		}
		
	
		if (items2[middle] < key)
		{
			items2.erase(items2.begin(), items2.begin() + middle + 1);
			index += (middle + 1);
			continue;
		}
		
		if (items2[middle] > key)
		{
			items2.erase(items2.begin() + middle, items2.begin() + items2.size());
		}
	
	}
}






template <typename Comparable>
int helper(vector<Comparable> &items2, const int key, int even_odd, int middle,
int index)
{	
	if((items2.size() == 1) && (items2[0] != key))
	{
		return -1;
	}
	
	even_odd = 2;
	if (items2.size() % 2 == 1)
	{
		even_odd = 1;
	}
	
	middle = ((items2.size() - even_odd)/2);

	if (items2[middle] == key)
	{
		return (index + middle);
	}
		
	if (items2[middle] < key)
	{
		items2.erase(items2.begin(), items2.begin() + middle + 1);
		index += (middle + 1);
		
		return helper(items2, key, even_odd, middle, index);
	}
	
	if (items2[middle] > key)
	{
		items2.erase(items2.begin() + middle, items2.begin() + items2.size());
		//simpleprint(items2);
		
		return helper(items2, key, even_odd, middle, index);
	}
}





template <typename Comparable>
int recBinSearch(vector<Comparable> &items, const int key)
{
	insertion_sort(items);

	
	vector<Comparable> items2;
	typename std::vector<Comparable>::iterator it = items2.begin();
	items2.insert(it, items.begin(), items.begin() + items.size());
	
	//int end = items2.size() - 1;
	if((key < items2[0]) || (key > items2[items2.size() - 1]))
	{
		return -1;
	}
	
	//simpleprint(items2);
	int even_odd = 2;
	int middle;
	int index = 0;
	
	return helper(items2, key, even_odd, middle, index);
}






#endif /* SEARCHSORT2_H_ */
