# makefile for building solutions for some Project Euler problems
#

BUILD_DIR := problems
CXXFLAGS  := -g -ggdb

CPP_FILES  := $(wildcard p*.cpp)
PROBLEM_N  := $(basename $(CPP_FILES))
PROBLEMS   := $(PROBLEM_N:%=$(BUILD_DIR)/%)

all : build_dir $(PROBLEMS)

build_dir:
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/% : %.cpp
	g++ $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(PROBLEMS)
