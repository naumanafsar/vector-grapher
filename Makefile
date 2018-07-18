all:
	g++ main.cpp `fltk-config --use-gl --ldstaticflags --cxxflags` -std=c++11 -o output 


run:
	./output
clean:
	rm -rf *.o
