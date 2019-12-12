SHELL := /bin/bash
CXX := g++
CXXFLAGS := -g -std=c++11 -O0 -Wall
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
EXEC := $(SRCS:.cpp=)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 
	# $(CXX) $(CXXFLAGS) $^ -o $@ -lpthread
$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $^
run: 
	./main
dep:
clean:
	-rm -rf *.o $(EXEC)
