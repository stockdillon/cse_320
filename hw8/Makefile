CPPFLAGS=-std=c++11 -g -O3

hash: main.o
	    g++ main.o -o hash

main.o: main.cpp BSTree.h HashTable.h HashTable.cpp BSTree.cpp
	g++ $(CPPFLAGS) -c main.cpp
