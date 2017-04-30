// What: we made a sudoku solver, functions for main class
// Who: Aaron Hamilton, Tom Reynolds, Robindiddams
// Date: April 28, 2016

#include "Puzzle.h"

Puzzle::Puzzle()
{

}

//Here begins the getters and setters ~~~~~~~~~~~~
void Puzzle::setRows(Group gArr[])
{
	rows[9] = gArr[9];
}

void Puzzle::setCols(Group cArr[])
{
	cols[9] = cArr[9];
}

void Puzzle::setBoxes(Group bArr[])
{
	boxes[9] = bArr[9];
}

void Puzzle::setPuzzle(Cell cArr[])
{
	puzzle[9][9] = cArr[9];
}

Group Puzzle::getRows()
{
	return rows[9];
}

Group Puzzle::getCols()
{
	return cols[9];
}

Group Puzzle::getBoxes()
{
	return boxes[9];
}

Cell Puzzle::getPuzzle()
{
	return puzzle[9][9];
}

//Here ends the getters and setters ~~~~~~~~~~~~




void Puzzle::openSudoku()
{
	//opens a sudoku.txt file and loads it into the puzzle array

	// 	Cell puzzle[9][9];
	int i, j, temp;

	fstream sudopen;

	sudopen.open("sudoku.txt", ios::in);
	if (sudopen.fail())
		cout << "Cant find sudoku file";

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudopen >> temp;
			puzzle[i][j].setAnswer(temp);
			// cout << temp << " ";
			cout << puzzle[i][j].getAnswer() << " ";
		}
		cout << endl;
	}

	sudopen.close();

	//debug cout statements

}

void Puzzle::loadPuzzle()
{
	//adds pointers to data from puzzle[][] array to groups

	int r, c, box, boxRow, boxCol, boxr, boxc, boxPos;

	//rows and cols
	for(r = 0; r < 9; r++)
	{
		for (c = 0; c < 9; c++)
		{
			rows[r].setArrVal(c, &puzzle[r][c]);
			puzzle[r][c].setRowNum(r);

			cols[c].setArrVal(r, &puzzle[r][c]);
			puzzle[r][c].setColNum(c);
		}		
	}

	//boxes, iterates through each box
	boxPos = 0;
	for (boxRow = 0; boxRow < 3; boxRow++)
	{
		for (boxCol = 0; boxCol < 3; boxCol++)
		{
			for(boxr = 0; boxr < 3; boxr++)
			{
				for (boxc = 0; boxc < 3; boxc++)
				{
					boxes[box].setArrVal(boxPos, &puzzle[boxr + (3 * boxRow)][boxc + (3 * boxCol)]);
					boxPos += 1;
					puzzle[boxr + (3 * boxRow)][boxc + (3 * boxCol)].setBoxNum(box);

				}
			}
		box += 1;
		boxPos = 0;
		}
	}

	cout << endl;

	vector<int> noPoss;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (puzzle[i][j].getAnswer() != 0)
			{
				noPoss.push_back(puzzle[i][j].getAnswer());
				puzzle[i][j].reduce(noPoss);
			}
		}
	}

}

void Puzzle::solve() 
{
	  //runs all the solving algorithms in the 
	 //order that we found most efficient.

	for (int k = 0; k < 100; k++)
	{

		for (int i = 0; i < 9; i++)
		{
			rows[i].reduceByNumbers();
		}
		for (int i = 0; i < 9; i++)
		{
			cols[i].reduceByNumbers();
		}
		for (int i = 0; i < 9; i++)
		{
			boxes[i].reduceByNumbers();
		}
		for (int j = 0; j < 9; j++)
		{
			rows[j].reduceByCells();
			cols[j].reduceByCells();
			boxes[j].reduceByCells();
		}
		
    	if (isSolved())
    	{
      		k = 100;
    	}
       	// printPrettyPuzzle(); //for fun debug
       	// cin.get() //for viewing pleasure
	}
}



bool Puzzle::isSolved()
{
	  //iterates though the puzzle array and
	 //checks if every spot has been filled

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if(puzzle[i][j].getAnswer() == 0)
        return false;
    }
  }
  return true;
}




void Puzzle::printPrettyPuzzle() 
{
	  //prints out the puzzle array, all 
	 //pretty and formatted
	cout << " =======================" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "|";
		for (int j = 0; j < 9; j++)
		{
			cout << getAscii(j) << puzzle[i][j].getAnswer();
		}
		cout << " |" << endl << getAsciiLine(i);

	}
	cout << " =======================" << endl << endl;
	
	// cin.get();  //debug
}

string Puzzle::getAscii(int num)
{
	 //used for print pretty puzzle function

	if ((num == 3) || (num == 6) || (num == 9))
	{
		return " | ";
	}
	else
		return " ";
}

string Puzzle::getAsciiLine(int num)
{
	 //used for print pretty puzzle function

	if ((num == 2) || (num == 5))
	{
		return "|-----------------------|\n";
	}
	else return "";
}


int Puzzle::getCellAnswer(int r, int c)
{
	  //used for UI part that just returns one
	 //solved cell

	return puzzle[r - 1][c - 1].getAnswer();
}



void Puzzle::userLoadPuzzle()
{
	 //lets user input their own sudoku puzzle manually

	int num;
	cout << "Please input the puzzle. Enter each number one at a time, starting in the top left corner and moving left to right, top to bottom. Enter zeroes for blank spaces. Press enter after each number.\n";
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> num;
			puzzle[i][j].setAnswer(num);
		}
	}
}
