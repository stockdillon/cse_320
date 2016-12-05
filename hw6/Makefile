CPPFLAGS=-std=c++11 -g -O3

library: main.o
	    g++ main.o -o library

main.o: main.cpp Library.h
	g++ $(CPPFLAGS) -c main.cpp