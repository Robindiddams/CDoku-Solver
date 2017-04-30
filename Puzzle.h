// What: we made a sudoku solver, this is the main class
// Who: Aaron Hamilton, Tom Reynolds, Robindiddams
// Date: April 28, 2016



#ifndef PUZZLE_H
#define PUZZLE_H


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