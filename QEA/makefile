SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -std=c++11 -Wall -ansi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main
main: $(OBJS)
	@$(CC) $(CXXFLAGS) $^ -o $@
%.o: %.cpp kenny_lib.h
	@$(CC) $(CXXFLAGS) -c $<
test:
	@# ./main [popsize] [item] [max_gen]
	@# ./main 10 1000 10000
clean: 
	rm -rf $(OBJS) main