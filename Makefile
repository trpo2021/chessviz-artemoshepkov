all: chess

chess: main.o lib.o
	g++ main.o lib.o -o chess

main.o: main.cpp
	g++ -c main.cpp

lib.o: lib.cpp
	g++ -c lib.cpp

clean:
	rm -rf *.o chess
