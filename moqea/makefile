SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -Wall -ansi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: moqea
moqea: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall %.o -o moqea
%.o: %.cpp global.h rand.h
	$(CC) $(CXXFLAGS) -c $<
clean: 
	rm -rf $(OBJS) 