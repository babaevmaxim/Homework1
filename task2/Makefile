CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pthread
LDFLAGS = -lgtest -lgtest_main -pthread

all: test_runner

test_runner: test.o SparseVector.o
	$(CC) $(CFLAGS) -o test_runner test.o SparseVector.o $(LDFLAGS)

test.o: test.cpp SparseVector.h
	$(CC) $(CFLAGS) -c test.cpp

SparseVector.o: SparseVector.cpp SparseVector.h
	$(CC) $(CFLAGS) -c SparseVector.cpp

clean:
	rm -f *.o test_runner

