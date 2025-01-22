CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
RUN=		&& ./solution
SHELL=		bash

all:		solution

solution:	solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

run:
	$(CXX) $(CXXFLAGS) -o solution solution.cpp $(RUN)
clean:
	rm -f solution

test:		test-output test-memory

test-output:	solution
	@echo Testing output...
	@diff --suppress-common-lines -y <(./solution < input) output

test-memory:	solution
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./solution < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

