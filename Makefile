all:
	g++ -c main.cpp event.cpp eventhandling.cpp

all: prog
prog: main.o event.o eventhandling.o
	g++ main.o eventhandling.o -o prog
output: main.cpp
	g++ -c main.cpp `fltk-config --use-gl --ldstaticflags --cxxflags`
eventhandling.o: eventhandling.cpp
	g++ -c eventhandling.cpp
event.o: event.cpp
	g++ -c event.cpp

run:
	./output
clean:
	rm -rf *.o
