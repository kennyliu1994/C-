CXX := g++
CXXFLAGS = -g -Wall
SRCS = main.cpp nsga2.cpp
OBJS = $(SRCS:.cpp=.o)

all: main
main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o nsga2 $(OBJS)
$(OBJS): $(SRCS)
clean:
	rm -rf nsga2 $(OBJS)
help:
	@echo " example: ./nsga2 [datasetName] [run] [iteration] "