CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		solution

solution:	solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY:		test test-output test-memory test-everything clean

clean:
	rm -f solution

test:		test-output test-memory

test-everything: test-output test-memory test-sequence

test-output:	solution
	@echo Testing output...
	@diff --suppress-common-lines -y <(./solution < input) output

test-memory:	solution
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./solution < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-sequence:	solution
	@echo Testing with s1ands2.txt...
	@echo Output:
	@./solution < s1ands2.txt
