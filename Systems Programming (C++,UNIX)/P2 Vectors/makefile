CFLAGS= -Wall -std=c++14 -g -pedantic-errors -O0

driver: Vector.o driver.o
	g++ -o driver driver.o Vector.o

driver.o: driver.cpp Vector.h
	g++ -c $(CFLAGS) driver.cpp

Vector.o: Vector.h Vector.cpp
	g++ -c $(CFLAGS) Vector.cpp
