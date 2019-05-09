SHELL := /bin/bash
CC := g++
CXXFLAGS = -g -Wall
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
vpath ../headers

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: main run
main: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@
	#g++ -g -Wall main.o -o main
$(OBJS): $(SRCS)
	$(CC) $(CXXFLAGS) -c $<
	#g++ -g -Wall -c main.cpp
run: 
	./main
clean: 
	rm -rf $(OBJS) main