SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -std=c++11 -Wall -ansi
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: moqea test
moqea: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall %.o -o moqea
%.o: %.cpp global.h rand.h
	$(CC) $(CXXFLAGS) -c $<
test:
	#./moqea kur <./gnuplot/kur.in
	#gnuplot -c gnuplot/test.gp kur gnuplot/kur.png final_pop.out
clean: 
	rm -rf $(OBJS) 