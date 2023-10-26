CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17

INCLUDES := -I include -I external/include -I external/include/commata/include/commata 


ROOTCONFIG :=root-config

#Get ROOT flags for include paths and libraries
ROOTCXXFLAGS := $(shell $(ROOTCONFIG) --cflags)
ROOTLIBS :=$(shell $(ROOTCONFIG) --glibs)


LDFLAGS := -L external/include/fmt
LDLIBS :=-lfmt

CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES) $(ROOTCXXFLAGS)


LDFLAGS := $(ROOTLIBS)

.PHONY: all clean

all: main

# If you add new source files in the src/ directory, remember to add the
# corresponding object file as a dependency here so that Make knows that it
# should build it and link to it
#
# Remove the Example object file when you are done looking at it, it doesn't
# contribute to the executable!
main: main.cxx 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@
	

clean:
	rm -v src/*.o main
