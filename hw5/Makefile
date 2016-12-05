CPPFLAGS=-std=c++11 -g

all: run

run: main.o
	g++ $(CPPFLAGS) main.o -o run

main.o: main.cpp mystack.h myminstack.h myqueue.h
	g++ $(CPPFLAGS) -c main.cpp

clean:
	rm *.o runCPPFLAGS=-std=c++11 -g -O3

Sort: main.o
	g++ main.o -o run

main.o: main.cpp
	g++ $(CPPFLAGS) -c main.cpp
