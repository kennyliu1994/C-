SHELL := /bin/bash
CC = g++
CXXFLAGS = -g -Wall -ansi
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
	./moqea fon <./gnuplot/fon.in
	gnuplot -c gnuplot/test.gp fon gnuplot/fon.png final_pop.out
clean: 
	rm -rf $(OBJS) 