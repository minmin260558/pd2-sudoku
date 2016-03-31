sudoku:sudoku.o main.o
	g++ -o sudoku sudoku.o main.o

sudoku.o:sudoku.cpp Sudoku.h
	g++ -c sudoku.cpp

main.o:main.cpp Sudoku.h
	g++ -c main.cpp

clean:
