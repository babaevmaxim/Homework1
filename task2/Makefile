CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lgtest -lgtest_main -pthread

all: run_tests

test_runner: SparseVector.cpp test.cpp
	 $(CXX) $(CXXFLAGS) SparseVector.cpp test.cpp -o test_runner $(LDFLAGS)

run_tests: test_runner
	 ./test_runner

clean:
	 rm -f test_runner *.o

