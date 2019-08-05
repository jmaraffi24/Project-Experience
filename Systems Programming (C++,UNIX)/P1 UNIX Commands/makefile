all: cat wc true false env

cat: cat.o
	g++ -o cat cat.o

cat.o: cat.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors cat.cpp

wc: wc.o
	g++ -o wc wc.o

wc.o: wc.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors wc.cpp

true: true.o
	g++ -o true true.o

true.o: true.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors true.cpp

false: false.o
	g++ -o false false.o

false.o: false.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors false.cpp

env: env.o
	g++ -o env env.o

env.o: env.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors env.cpp

clean:
	/bin/rm *.o cat wc true false env