// What: a sudoku solver
// Who: Robindiddams
// Date: April 29, 2017

#include "PrettyUI.h"
#include <iostream>



const int NUMBER_OF_FLAGS = 6;

char findAndSetFlags(char flag, char flagArray[]) {
	char flags[6] = {'p', 'v', 'o', 'r', 'c', 'U'}; // number of flags must be inserted here: flags[NUMBER_OF_FLAGS]
	char foundFlag = 0;
	for (int i = 0; i < NUMBER_OF_FLAGS; i++) {
		if (flag == flags[i]) {
			flagArray[i] = flags[i];
			foundFlag = flag;
		}
	}

	return foundFlag;
}

bool isFlagged(char flag, char flagArray[]) {
	for (int i = 0; i < NUMBER_OF_FLAGS; i++) {
		if (flagArray[i] == flag) {
			return true;
		}
	}
	return false;
}

//prints out the help message
void printHelp() {

	cout << "Command options:\n" <<
						"  -o <file>    write solved puzzle to <file>\n" <<
						"  -p           print to console\n" <<
						// "  -v           verbose\n" <<
						"  -r <row>     solve just row <row>, only takes numbers 1-9\n" <<
						"  -c <col>     solve just column <col>, only takes numbers 1-9\n" <<
						"  -U           pretty UI, all other args are ignored and the hand-holding ui will walk you through this\n" <<
						"\n" <<
						"Example Usage:\n" <<
						"  ./CDoku sudoku.txt -o solved.txt        Solves a puzzle in file sudoku.txt and writes out to solved.txt" <<
						endl;
}

int main(int argc, char* argv[]) {


	/*
		GET ARGUMENTS
	*/


	//these will be set by the flags
	string outputFile = "", row, column, inputFile = "";

	// this array will be filled with flags that are found
	char flags[NUMBER_OF_FLAGS];
	char foundFlag;

	bool skipNextArg = false;


	for (int i = 0; i < NUMBER_OF_FLAGS; i++) {
		flags[i] = 0;
	}

	if (argc > 1) {

		//iterate over all args
		for (int i = 1; i < argc; i++) {
			// cout << argv[i] << endl;
			if (argv[i][0] == '-') {
				//iterate through flag argument for flags
				for (int j = 1; argv[i][j] != 0; j++) {
					// cout << "iterate through arg " << argv[i] << " " << argv[i][j] << endl;
					 //findAndSetFlags, fills 'flags', with a flag if the given char is 
					//valid, returns the char of that flag if it is.
					foundFlag = findAndSetFlags(argv[i][j], flags);
					
					//flags that need to grab next piece of info
					if (foundFlag == 'o') {
						outputFile = argv[i + 1];
						skipNextArg = true;
					}
					else if (foundFlag == 'r') {
						row = argv[i + 1];
						skipNextArg = true;
					} 
					else if ( foundFlag == 'c') {
						column = argv[i + 1];
						skipNextArg = true;
					}
				}
				
				skipNextArg ? i++ : NULL;

				// cout << " and were done with that arg" << endl;

			} else {
				//unflagged item, should be our input file
				inputFile = argv[i];
			}
		}

		// // if you want debug on the flags:
		// cout << "flag array: ";
		// for (int i = 0; i < NUMBER_OF_FLAGS; i++) {
		// 	cout << flags[i] << " ";
		// }
		// cout << endl;
		
		// cout << "output file: " << outputFile << endl
		// 	<< "input file: " << inputFile << endl
		// 	<< "row to find: " << row << endl
		// 	<< "col to find: " << column << endl;
		
		/*
			PARSE FLAGS
		*/

		if( (isFlagged('r', flags) || isFlagged('c', flags)) && isFlagged('o', flags)) {
			cout << "Error: -o cannot be used with -c or -r" << endl;
			return 1;
		}
		if ( inputFile == "" ) {
			cout << "Error: no input file" << endl;
			return 1;
		}


		

		if (isFlagged('U', flags)) {
			//if we find a U flag we can ignore all other data
			prettyUI();
		} else {

			Puzzle puzz;
			puzz.openSudoku(inputFile);
			puzz.loadPuzzle();
			puzz.solve();


			//NOTE rows and cols start at the top left and with 1
			if (isFlagged('r', flags) && isFlagged('c', flags)) {
				//find one cell
				cout << "The number in cell (" << row << "," << column << ") is: " << puzz.getCellAnswer(std::stoi( row ), std::stoi( column)) << endl;
			} else if (isFlagged('r', flags)) {
				//find one row
				cout << "The numbers in row (" << row << ") is: " << puzz.getRowAnswer(stoi( row )) << endl;				
			} else if (isFlagged('c', flags)) {
				// find one col
				cout << "The numbers in column (" << column << ") is: " << puzz.getColAnswer(stoi( column )) << endl;				
			} else {
				//handle outputs
				if (isFlagged('o', flags)) {
					//output
					puzz.writeOutSudoku(outputFile);
				}
				if (isFlagged('p', flags)) {
					//print all nice
					puzz.printPrettyPuzzle();
				}
			}
		}
		

	} else {
		printHelp();
	}



	// Puzzle beans;
	// cout << "Here is what I found: \n";
	// beans.openSudoku();
	// beans.loadPuzzle();
	// beans.solve();
	// beans.printPrettyPuzzle();
	return 0;
}