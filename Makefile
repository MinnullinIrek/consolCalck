CC=g++
CFLAGS=-std=c++11
main: main.o parser.o
	$(CC) $(CFLAGS) -o reg main.o parser.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
parser.o: parser.cpp parser.h
	$(CC) $(CFLAGS) -c parser.cpp
clean:
	rm -f reg *.o
