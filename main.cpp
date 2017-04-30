// What: a sudoku solver
// Who: Robindiddams
// Date: April 29, 2017

#include "PrettyUI.h"
#include <iostream>


int main(int argc, char* argv[]) {
	cout << argc << endl;

	Puzzle beans;
	cout << "Here is what I found: \n";
	beans.openSudoku();
	beans.loadPuzzle();
	beans.solve();
	beans.printPrettyPuzzle();
	// prettyUI();
	return 0;
}