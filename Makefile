# makefile for building solutions for some Project Euler problems
#

CPP_FILES := $(wildcard p*.cpp)
PROBLEMS  := $(basename $(CPP_FILES))

CXXFLAGS = -g -ggdb

all : $(PROBLEMS)

% : %.cpp
	g++ $(CXXFLAGS) -o $@ $<


clean:
	rm -rf $(PROBLEMS)
