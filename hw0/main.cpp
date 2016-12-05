//============================================================================
// Name        : main.cpp
// Author      : Sebnem Onsay
// Version     :
// Copyright   : Your copyright notice
// Description : Homework 0
//============================================================================

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "LinearSearch.h"
#include <fstream>
#include <time.h>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>


using namespace std;




int main()
{

	//ifstream inClientFile("input.txt",ios::in);
	ifstream inClientFile("input.in",ios::in);
	// check to see if file opening succeeded
	if ( !inClientFile.is_open() ) {
		cout<<"Could not open file\n";
		return 0;
	}
	//time_t t1 = 0;

	vector<int> data;
	//read input
	int input_t;

	//load vector
	while( inClientFile >> input_t) {
		data.push_back(input_t);

	}


	auto t1 = std::chrono::high_resolution_clock::now();

	//Testing1
	//testing for hard-coded value!
	//int key=11268; // comment out
	//bool isFound= linearSearch(data,key); // comment out

	//Testing2
	//testing with random value
	srand(static_cast<unsigned int>(time(0)));
	int randomval=1+ rand()%1000000;

	//unless the linearSearch method is completed, main method will not work
	bool isFound=linearSearch(data,randomval);
	auto t2 = std::chrono::high_resolution_clock::now();

	if (isFound)
		cout<<"The key value --> " << randomval << " was found! " << endl;
	else
		cout<<"The key value --> " << randomval << " was not found! " << endl;

	cout << "Size of the vector : "<< data.size() << endl;
	cout << "Linear Search method  took "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
			<< " nanoseconds \n";    inClientFile.close();

	return 0;


}
