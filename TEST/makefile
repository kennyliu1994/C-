SHELL := /bin/bash
CC := g++
CXXFLAGS = -g -Wall
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main run
main: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall main.o lib.o -o main
$(OBJS): $(SRCS)
	$(CC) $(CXXFLAGS) -c $^
	#g++ -g -Wall -c main.cpp lib.cpp
run: 
	./main
clean: 
	rm -rf $(OBJS) main