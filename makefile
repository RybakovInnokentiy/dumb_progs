
main: main.o
	g++ main.o List.o -o main
main.o: main.cpp
	g++ -g -c main.cpp List.cpp

.PHONY: clean
clean: 
	del main.o List.o main