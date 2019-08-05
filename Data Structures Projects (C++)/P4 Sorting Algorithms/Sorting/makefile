CFLAGS= -Wall -std=c++14 -g  -pedantic-errors -O0

main: Main.o Sorting.o
	g++ -o main Main.o Sorting.o

Main.o: Main.cpp Sorting.h
	g++ -c $(CFLAGS) Main.cpp

Sorting.o: Sorting.cpp Sorting.h
	g++ -c $(CFLAGS) Sorting.cpp

clean:
	rm *.o
	rm main
