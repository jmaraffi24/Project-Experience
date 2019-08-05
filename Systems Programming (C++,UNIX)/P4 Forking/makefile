all: size newer dirlist forkpid

size: size.o
	g++ -o size size.o

size.o: size.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors size.cpp

newer: newer.o
	g++ -o newer newer.o

newer.o: newer.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors newer.cpp

dirlist: dirlist.o
	g++ -o dirlist dirlist.o

dirlist.o: dirlist.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors dirlist.cpp

forkpid: forkpid.o
	g++ -o forkpid forkpid.o

forkpid.o: forkpid.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors forkpid.cpp

clean:
	/bin/rm *.o size newer dirlist forkpid




