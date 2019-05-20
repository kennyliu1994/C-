SHELL := /bin/bash
CXX := g++
CXXFLAGS = -g -Wall
SRCS = main.cpp nsga2.cpp
OBJS = $(SRCS:.cpp=.o)

all: main run
main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o nsga2 $(OBJS)
$(OBJS): $(SRCS)
clean:
	rm -rf nsga2 $(OBJS) output.txt
run:
	./nsga2 KUR 1 250
help:
	@echo " example: ./nsga2 [datasetName] [run] [iteration] "