// Class: CSI-240-01
// Assignment: final project
// What we did: we made a sudoku solver
// Who: Aaron Hamilton, Tom Reynolds, Robin Diddams
// Date: April 28, 2016
// Takes a "sudoku.txt" file that resembles the following(Zeros being empty spaces):
// 0 5 7 6 0 9 0 0 0
// 0 0 0 0 3 0 0 7 0
// 4 3 0 8 0 0 1 0 9
// 0 1 0 5 4 0 3 0 0
// 0 0 5 3 0 6 7 0 0
// 0 0 6 0 8 7 0 2 0
// 9 0 3 0 0 1 0 5 7
// 0 7 0 0 2 0 0 0 0
// 0 0 0 7 0 3 9 8 0


#ifndef PUZZLE_H
#define PUZZLE_H
//#include "Main.h"
#include "Group.h"
#include "Cell.h"
#include <string>
#include <fstream>


class Puzzle
{
private:
	Group rows[9];
	Group cols[9];
	Group boxes[9];

	Cell puzzle[9][9];

public:
	//constructor
	Puzzle();

	//setters
	void setRows(Group[]);
	void setCols(Group[]);
	void setBoxes(Group[]);

	void setPuzzle(Cell[]);

	//getters
	Group getRows();
	Group getCols();
	Group getBoxes();

	Cell getPuzzle();

	//excelent algorithms
	void openSudoku();
	void loadPuzzle();
	void reduceByNumbers();
	void solve();
	bool isSolved();
	void printPuzzle();
	void printPrettyPuzzle();
	string getAscii(int);
	string getAsciiLine(int);
	int getCellAnswer(int, int);
	void userLoadPuzzle();

	//deconstructor
	// ~Puzzle();
	friend class Cell;
};

#endif