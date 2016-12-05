#include <iostream>

#include "HashTable.h"


//constructor
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
    : tableSize(initTableSize), dataTable( new BSTree<DataType, KeyType>[initTableSize] )
{
	cout << "in constructor method..." << endl; // remove
	//typename BSTree<DataType,KeyType>::BSTree dataTable[tableSize]; //
	//this->dataTable[tableSize];
	//typename BSTree<DataType,KeyType>::BSTree *dataTable[tableSize];
	//cout << tableSize << endl; // remove
}



//copy constructor 
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& source) 
{
	cout << "in COPY constructor method..." << endl; // remove
	tableSize = source.tableSize;
	dataTable = source.dataTable;
}



//assignment operator
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>&
HashTable<DataType, KeyType>::operator=(const HashTable& source) 
{
	cout << "in assignmentOperator method..." << endl; // remove
    if (&source != this)
    {
		delete[] dataTable;
		copyTable(source);
    }

    return *this;
}



//copyTable
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) 
{

}



//destructor
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() 
{
	cout << "in destructor method..." << endl; // remove
	delete[] dataTable;
}




/*
//hash
template <typename DataType, typename KeyType>
int HashTable<DataType, KeyType>::hash( const KeyType& obj) 
{
	return hash_M( obj.hash(), capacity() );
}
*/




//insert
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem) 
{
	cout << "in insert method..." << endl; // remove
	size_t hashed_key = newDataItem.hash(newDataItem.getKey());
	cout << "HASH VALUE: " << hashed_key << endl;
	hashed_key = hashed_key % tableSize;
	cout << "HASH VALUE (modded): " << hashed_key << endl;
	dataTable[hashed_key].insert(newDataItem);
}




//remove
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) 
{
	cout << "in remove method..." << endl; // remove
	
	//size_t hashed_key = hash_M(deleteKey, tableSize);
	size_t hashed_key = DataType::hash(deleteKey);
	cout << "HASH VALUE: " << hashed_key << endl; // remove
	hashed_key = hashed_key % tableSize;
	cout << "HASH VALUE (modded): " << hashed_key << endl; // remove
	dataTable[hashed_key].remove(deleteKey);
	
}



//retrieve
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey,
					    DataType& returnItem) const
{
	cout << "in retrieve method..." << endl; // remove
	size_t hashed_key = DataType::hash(searchKey);
	hashed_key = hashed_key % tableSize;
	return dataTable[hashed_key].retrieve( searchKey, returnItem );
}




//clear
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() 
{
	cout << "in clear method..." << endl; // remove
	delete[] dataTable;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}



//isempty
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const 
{
	cout << "in isEmpty..." << endl; //remove
	for(unsigned i = 0 ; i < tableSize ; i++)
	{
		//cout << "displaying Table..." << endl; //remove
		//dataTable[i].showStructure(); // remove
		if(!dataTable[i].isEmpty()) return false;
	}
	return true;
}




//showstructure 
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const 
{
	
	cout << "in showStructure method..." << endl; // remove
	if(this->isEmpty())
	{
		cout << "Empty hash table" << endl;
		return; 
	}
	cout << this->tableSize << endl; // remove	
	
    for (int i = 0; i < tableSize; ++i) { // onsay code
	cout << i << ": ";	// onsay code
	dataTable[i].writeKeys();	//onsay code
    }
}
