output: main.o circle.o
	g++ main.o circle.o -o output

main.o: main.cpp
	g++ main.cpp

message.o: circle.cpp circle.h
	g++ -c circle.cpp

clean: rm *.o output