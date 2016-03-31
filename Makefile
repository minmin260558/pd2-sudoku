sudoku:sudoku.o main.o
	g++ -o sudoku sudoku.o main.o

sudoku.o:sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

main.o:main.cpp sudoku.h
	g++ -c main.cpp

clean:
