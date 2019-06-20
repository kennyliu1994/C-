SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -Wall -ansi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: nsga2
nsga2: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall nsga2.o lib.o -o nsga2
%.o: %.cpp global.h rand.h
	$(CC) $(CXXFLAGS) -c $<
clean: 
	rm -rf $(OBJS) 