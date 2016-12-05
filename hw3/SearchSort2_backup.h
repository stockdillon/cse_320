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
	int even_odd = 2;
	int middle;
	int index = 0;
	
	vector<Comparable> items2;
	typename std::vector<Comparable>::iterator it = items2.begin();
	items2.insert(it, items.begin(), items.begin() + items.size());
	
	simpleprint(items);
	simpleprint(items2);
	
	
	for(int i=0; i<5; i++)
	{
		//cout << endl << "----------------loop: " << i << "-----------------" << endl << endl << endl;
		even_odd = 2;
		
		if (items2.size() % 2 == 1)
		{
			even_odd = 1;
		}
		
		middle = ((items2.size() - even_odd)/2);
		
		
		/*
		cout << "Key: " << key << endl;
		cout << "MIDDLE: " << middle << "  items[middle]: " << items[middle] << endl << endl;
		*/
		
		
		if (items2[middle] == key)
		{
			cout << "KEY WAS FOUND ---- " << endl;
			cout << "middle: " << middle << endl << "index: " << index << endl;
			cout << "Returning index + middle: " << (index + middle) << endl;
			return (index + middle);
		}
		
	
		if (items2[middle] < key)
		{
			cout << endl << "items2[middle] < key" << endl << endl;
			items2.erase(items2.begin(), items2.begin() + middle + 1);
			//vector<Comparable> items2;
			//typename std::vector<Comparable>::iterator it = items2.begin();
			//it = items2.begin()
			//items2.insert(it, items.begin() + middle + 1, items.begin() + items.size());
			cout << "second half of vector: " << endl;
			simpleprint(items2);
			index += (middle + 1);
			continue;
		}
		
		if (items2[middle] > key)
		{
			cout << endl << "items2[middle] > key" << endl;
			items2.erase(items2.begin() + middle, items2.begin() + items2.size());
			//vector<Comparable> items2;
			//typename std::vector<Comparable>::iterator it = items2.begin();
			//items2.insert(it, items.begin() + middle + 1, items.begin() + items.size());
			cout << "first half of vector:  " << endl;
			simpleprint(items2);
		}
	
	}
}



template <typename Comparable>
int helper(vector<Comparable> &items, const int key, int even_odd, int middle,
int index)
{
	if((items.size() == 1) && (items[0] != key))
	{
		return -1;
	}
	even_odd = 2;
	if (items.size() % 2 == 1)
	{
		even_odd = 1;
	}
	
	middle = ((items.size() - even_odd)/2);

	if (items[middle] == key)
	{
		/*
		cout << "KEY WAS FOUND ---- " << endl;
		cout << "middle: " << middle << endl << "index: " << index << endl;
		cout << "Returning index + middle: " << (index + middle) << endl;
		*/
		return (index + middle);
	}
		
	if (items[middle] < key)
	{
		cout << endl << "items[middle] < key" << endl;
		//items.erase(items.begin(), items.begin() + middle + 1);
		vector<Comparable> items2;
		typename std::vector<Comparable>::iterator it = items2.begin();
		items2.insert(it, items.begin() + middle + 1, items.begin() + items.size());
		cout << "items2.size(): " << items2.size() << endl;
		cout << endl << endl << "items2: " << endl;
		simpleprint(items2);
		
		cout << "second half of vector: " << endl;
		simpleprint(items);
		index += (middle + 1);
		
		return helper(items, key, even_odd, middle, index);
	}
	
	if (items[middle] > key)
	{
		cout << endl << "items[middle] > key" << endl;
		items.erase(items.begin() + middle, items.begin() + items.size());
		cout << "first half of vector:  " << endl;
		simpleprint(items);
		
		return helper(items, key, even_odd, middle, index);
	}
}



template <typename Comparable>
int recBinSearch(vector<Comparable> &items, const int key)
{
	int end = items.size() - 1;
	if((key < items[0]) || (key > items[end]))
	{
		return -1;
	}
	
	simpleprint(items);
	int even_odd = 2;
	int middle;
	int index = 0;
	
	return helper(items, key, even_odd, middle, index);
}
	


#endif /* SEARCHSORT2_H_ */
