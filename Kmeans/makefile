SHELL := /bin/bash
CC := g++
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXE = $(OBJS:.o=)
CXXFLAGS = -g -Wall
.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean
all: $(EXE) run
$(EXE): $(OBJS)
	$(CC) $(CXXFLAGS) $< -o $@
	#g++ -g -Wall kmeans.o -o kmeans
$(OBJS): $(SRCS)
	$(CC) $(CXXFLAGS) -c $<
	#g++ -g -Wall -c Kmeans.cpp
run: 
	./$(EXE)
clean: 
	rm -rf $(OBJS) $(EXE)