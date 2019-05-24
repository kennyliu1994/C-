SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -Wall -ansi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: nsga2 run
nsga2: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall nsga2.o lib.o -o nsga2
$(OBJS): $(SRCS)
	$(CC) $(CXXFLAGS) -c $<
	#g++ -g -Wall -c nsga2.cpp
clean: 
	rm -rf $(OBJS) 