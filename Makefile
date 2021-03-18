CFLAGS = -Wall -Wextra -Werror
CC = g++

chess: main.o lib.o
	$(CC) $(CFLAGS) main.o lib.o -o chess

main.o: main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

lib.o: lib.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

libchess.a: lib.o
	ar rcs $@ $^

clean:
	rm -rf *.o *.exe
