/*
 * LinearSearch.h
 *
 *  Created on: Today
 *      Author: onsayse
 */

#ifndef LINEARSEARCH_H_
#define LINEARSEARCH_H_
#include <vector>
using namespace std;
/**
 * @pre: array(vector) is non empty
 * @return bool
 * @post: the value returned true if found false otherwise
 */
//your code goes here!
template <typename Comparable>
bool linearSearch( vector<Comparable> &data, const int randomval)
{
	unsigned size = data.size();
	for (unsigned i=0; i<size; i++)
	{
		if (data[i] == randomval)
		{
			return 1;
		}
	}
	return 0;
};


#endif /* LINEARSEARCH_H_ */


