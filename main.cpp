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



#include <iostream>

#include "Puzzle.h"

using namespace std;


int inputSel = 0,
	answerSel = 0;

int mainMenu();
int answerMenu();
void cellSel(Puzzle* beanss);
void shutDown();

int main()
{
	//mostly UI
	//done by Aaron

	bool repeat = true;

	while(repeat == true)
	{
		Puzzle beans;

		
		inputSel = mainMenu();
		
		switch (inputSel)
		{
		case 1:
			//call file input function
			cout << "Here is what I found: \n";
			beans.openSudoku();
			beans.loadPuzzle();
			beans.solve();

			break;
		case 2:
			//call manual input function
			beans.userLoadPuzzle();
			beans.loadPuzzle();
			beans.solve();

			break;
		case 3:
			shutDown();
			repeat = false;
			break;
		}
		
		if(inputSel == 3)
			repeat = false;
		else
		{
			answerSel = answerMenu();
			
			switch (answerSel)
			{
			case 1:
				{
				//call function that prints whole solved puzzle
				beans.printPrettyPuzzle();
				break;
				}
			case 2:
				{
				Puzzle* puz = &beans;
				cellSel(puz);
				break;
				}
			case 3:
				{
				shutDown();
				repeat = false;

				break;
				}	
			}
			
		}
		
		cin.get();
	}
	return 0;
}

int mainMenu()
{
	//more UI 

	int sel;
	bool validInput = false;

	while (!validInput)
	{
		cout << "File Input Options" << endl;
		cout << "1. File" << endl;
		cout << "2. Manually" << endl;
		cout << "3. Exit" << endl;
		cout << "Choose an input method: "; cin >> sel;

		if (sel <= 0 || sel >= 4)
		{
			cout << "Invalid input. Try again" << endl;
			validInput = false;
		}
		else validInput = true;
	}

	return sel;
}

int answerMenu()
{
	//Even more UI!

	int sel;
	bool validInput = false;
	while (!validInput)
	{
		cout << "Answer Output Options" << endl;
		cout << "1. Whole puzzle" << endl;
		// cout << "2. Step by step" << endl;
		cout << "3. Cell selection" << endl;
		cout << "4. Exit" << endl;
		cout << "Which output method would you like?: "; cin >> sel;

		if (sel <= 0 || sel >= 5)
		{
			cout << "Invalid input. Try again" << endl;
			validInput = false;
		}
		else validInput = true;
	}

	return sel;
}

void cellSel(Puzzle* p)
{
	
	int r, c;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Enter row number: "; cin >> r;
		cout << "Enter column numner: "; cin >> c;
		cout << endl;

		if ((r <= 0 || r > 9) || (c <= 0 || c > 9))
		{
			cout << "Invalid input. Try again" << endl;
			validInput = false;
		}
		else validInput = true;
	}

	cout << "The solution to the cell at row " << r << " column " << c << ", is : " << p->getCellAnswer(r, c) << endl << endl;
}

void shutDown()
{
	//abstraction FTW
	cout << "Goodbye!" << endl;

}