# A sudokuSolver

# the compiler to use.
CC=g++

# C flags 
CFLAGS=-Wall

all:
	$(CC) $(CFLAGS) src/*.cpp -o CDoku

clean:
	rm CDoku