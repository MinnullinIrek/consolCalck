CC=g++
CFLAGS=-std=c++11
test: test.o ../parser.o
	$(CC) $(CFLAGS) -o test test.o ../parser.o -lcppunit
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
parser.o: ../parser.cpp ../parser.h
	$(CC) $(CFLAGS) -c ../parser.cpp
clean:
	rm -f test *.o
