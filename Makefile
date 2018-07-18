all:
	g++ main.cpp `fltk-config --use-gl --ldstaticflags --cxxflags` -std=c++11 -o haha

run:
	./output
clean:
	rm -rf *.o
