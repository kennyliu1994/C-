SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -Wall -ansi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main run
main: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall main.o lib.o -o main
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $<
run: 
	./main
clean: 
	rm -rf $(OBJS) 