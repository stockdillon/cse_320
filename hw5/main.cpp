/*


By Dillon Stock
October 23, 2016
Homework 5



*/



#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "mystack.h"
#include "myminstack.h"
#include "myqueue.h"
#include <fstream>
using namespace std;


int main(int argc, const char * argv[])
{
	/* read from file
	 *
	 */
	//ifstream inClientFile("inputfile",ios::in);
	ifstream inClientFile("inputfile2",ios::in);
	// check to see if file opening succeeded

	if ( !inClientFile.is_open() ) {
		cout<<"Could not open file\n";
		return 0;
	}
	vector<int> nums;

	int input_t;
	while( inClientFile >> input_t) {
		nums.push_back(input_t);
	}





	cout<<"The min stack is built " << endl;
	minstack<int> getminstack;
	//MyStack<int> getMyStack;  // /////// ------------------------
	for (int i = 0; i < nums.size(); i++){
		getminstack.push(nums[i]);
		//getMyStack.push(nums[i]); ///////////// -----------------
                cout<<"top is --> "<< getminstack.gettop()<<endl;
	}
	
	//cout << endl << endl << "Testing MyStack.display() : " << endl;
	//getMyStack.display(); ///////// ------------------
	


        // The min stack contains:
        cout << "After building the min stack. " ;
        cout<< "What is on Top of My Min Stack ? " << " It is --> " ;

	cout << getminstack.gettop() << endl;

        cout << "\n******************Testing min stack implementation few times *************\n";
	
	
	//cout << "MIN STACK AFTER BUILDING" << getminstack.stack_of_min->display() << endl;
	//cout << "MAIN STACK AFTER BUILDING" << getminstack.display() << endl;
	
	
	
	
	
	cout << "The current element on top of the stack is: " <<getminstack.getMin() << endl;
	cout << "The min is: "<< getminstack.getMin() << endl;
	cout << "Pop the current element --> " << getminstack.gettop() << endl;
	getminstack.pop(); //pop 2
	cout << "The min is: "<< getminstack.getMin() << endl;
        cout << "Pop the current element --> " << getminstack.gettop() << endl;
        getminstack.pop(); //pop 11
        cout << "The min is: "<< getminstack.getMin() << endl;
        cout << "Pop the current element --> " << getminstack.gettop() << endl;
        getminstack.pop(); //pop 6
        cout << "The min is  : "<< getminstack.getMin() << endl;
        cout << "Pop the current element --> " << getminstack.gettop() << endl;
        getminstack.pop(); //pop 5
        cout << "The min is  : "<< getminstack.getMin() << endl;
        cout << "Pop the current element --> " << getminstack.gettop() << endl;
        getminstack.pop(); //pop 4
        cout << "The min is  : "<< getminstack.getMin() << endl;
        cout << "Pop the current element --> " << getminstack.gettop() << endl;
        getminstack.pop(); //pop 7
        //cout << "The min is  : "<< getminstack.getMin() << endl;
        //cout << "Pop the current element --> " << getminstack.gettop() << endl;


	






	myqueue<int> queuebystack;
	for (int i = 0; i < nums.size(); i++){
		queuebystack.push(nums[i]);
	}

	cout << "\n******************The second part : Queue implementation ******************\n";
        cout << "Is the queue empty right now?\n" << ((queuebystack.empty()) ? "Yes" : "No")<< endl;
	cout << "pop all elements in queue" << endl;
	for (int i = 0; i < nums.size(); i++){
		cout << queuebystack.gettop() << endl;;
		queuebystack.pop();
	}
	cout << "Is the queue empty right now?\n" << ((queuebystack.empty()) ? "Yes" : "No")<< endl;





	return 0;

}


