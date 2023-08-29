all:
	g++ -c SquareSolver.cpp solve.cpp output.cpp input.cpp compare.cpp fileinput.cpp tests.cpp
	g++ SquareSolver.o solve.o output.o input.o compare.o fileinput.o tests.o
