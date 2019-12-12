SHELL := /bin/bash
CXX := g++
CXXFLAGS := -g -std=c++11 -O3 -Wall
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
EXEC := $(SRCS:.cpp=)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 
$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $^
run: 
	# ./main [run] [iter] [pop] [item]
	./main 1 1000 10 1000
dep:
clean:
	-rm -rf *.o $(EXEC)