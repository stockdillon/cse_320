CPPFLAGS=-std=c++11 -g -O3

search: main.o
	    g++ main.o -o search

main.o: main.cpp LinearSearch.h
	g++ $(CPPFLAGS) -c main.cpp
