CPPFLAGS=-std=c++11 -g -O3

maxheap: main.o
	    g++ main.o -o maxheap

main.o: main.cpp MaxHeap.h
	g++ $(CPPFLAGS) -c main.cpp
