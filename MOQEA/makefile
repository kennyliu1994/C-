SHELL := /bin/bash
CC := g++
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXE = $(OBJS:.o=)
CXXFLAGS = -g -Wall

.SUFFIXES:
.SUFFIXS: .c .cpp .o
.PHONY: all clean run

all: linker $(EXE) run
linker: 
	g++ -c lib.cpp
	ar -rc lib.a lib.o
$(EXE): $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@ lib.a
	#g++ -g -Wall main.o -o main
$(OBJS): $(SRCS)
	$(CC) $(CXXFLAGS) -c $^
	#g++ -g -Wall -c main.cpp
run: 
	./$(EXE)
clean: 
	rm -rf $(OBJS) $(EXE) lib.a lib.o