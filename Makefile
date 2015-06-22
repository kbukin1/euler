# makefile for building solutions for some Project Euler problems
#

BUILD_DIR := problems
CXXFLAGS  := -g -ggdb

CPP_FILES      := $(wildcard p*.cpp)
PROBLEM_NAMES  := $(basename $(CPP_FILES))
PROBLEMS       := $(PROBLEM_NAMES:%=$(BUILD_DIR)/%)

all : build_dir report

$(BUILD_DIR)/% : %.cpp
	g++ $(CXXFLAGS) -o $@ $<

build_dir:
	@mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(PROBLEMS)

report: $(PROBLEMS) .FORCE
	@echo Number of found solutions: $(words "$(PROBLEM_NAMES)")
	@echo Number of built solutions: $(words "$(PROBLEMS)")

.FORCE: 
