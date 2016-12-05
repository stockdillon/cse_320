/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: onsayse
 *
 * Created on November 2, 2016, 7:41 PM
 */

#include <cstdlib>
#include <vector>
#include "MaxHeap.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream inClientFile("numbers_small.txt", ios::in);
    //ifstream inClientFile("numbers.txt", ios::in);

    if (!inClientFile.is_open()) {
        cout << "Could not open file\n";
        return 0;
    }
    vector<int> nums;

    int input_t;
    int i=0;
    while (inClientFile >> input_t) {
        nums.push_back(input_t);
     }

    myMaxHeap<int> max_heap(nums);

    // display the heap in level order
    cout << "\n Verify Constructor, Display the heap: \n" << endl;
    max_heap.display();
    cout<< "The height of this binary heap is " <<max_heap.getHeight()<< endl;
  cout<< "The number of nodes  " <<max_heap.getNumberOfNodes()<< endl;

    cout<<"Add new item (duplicate)"<<endl;
    max_heap.add(20);
    max_heap.display();
    // Insert heap
    max_heap.add(400);
    max_heap.add(1);
    cout<< "The top value is " << max_heap.peekTop()<<endl;
    // display the heap in level order
    cout<< "\n Verify Insert, Display the heap: \n" <<endl;
    max_heap.display();
    
    max_heap.increaseKey(4, 50);
    max_heap.decreaseKey(1, 400);
    
    // display the heap in level order
    cout<< "\n Verify IncreaseKey and DecreaseKey, Display the heap: \n" <<endl;
    max_heap.display();   
    
    max_heap.remove();
    
    // display the heap in level order
    cout<< "\n Verify Remove, Display the heap:" <<endl;
    max_heap.display();
    max_heap.clear();
    cout<<"Show heap after clear" << endl;
    max_heap.display();
    //should throw an underflow exception
 
    
}

