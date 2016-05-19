all: compile test

compile:
	g++ -std=c++11 -O3 -o exe_O3_cpp11  Main.cpp Coordinates.cpp -I./ 
	g++ -std=c++11 -O2 -o exe_O2_cpp11  Main.cpp Coordinates.cpp -I./ 
	g++ -O2            -o exe_O2        Main.cpp Coordinates.cpp -I./ 
	g++ -std=c++11     -o exe_cpp11     Main.cpp Coordinates.cpp -I./ 
	g++                -o exe           Main.cpp Coordinates.cpp -I./ 

test:
	./exe
	./exe_O2
	./exe_cpp11
	./exe_O2_cpp11
	./exe_O3_cpp11
