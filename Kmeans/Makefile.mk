CC=g++
OBJECTS:=*.o
CXXFLAGS:=-g -Wall
all:%.cpp
	$(CC) $(CXXFLAGS) $< -o $* 
	#g++ -g -Wall Kmeans.cpp -o Kmeans 
.PHONY:clean
clean:
	@rm -rf *.o