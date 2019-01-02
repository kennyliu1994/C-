CC=g++
#編譯
OBJECTS:=*.o
CXXFLAGS:=-g -Wall
#參數
.PHONY:all clean
#忽略檔名
all:%.cpp
	$(CC) $(CXXFLAGS) $< -o $* 
	#g++ -g -Wall Kmeans.cpp -o Kmeans 
clean:
	@rm -rf *.o