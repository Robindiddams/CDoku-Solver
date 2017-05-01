// What: The cell class has a vector of possible ints that it could be, and identifiers for what it belongs to
// Who: Robindiddams, Aaron Hamilton, Tom Reynolds
// Date: April 29, 2017

#include "Cell.h"

//Here begins the getters and setters ~~~~~~~~~~~~
void Cell::reduce(vector<int>poss)
{
	possibilities = poss;
}

void Cell::setAnswer(int ans)
{
	answer = ans;
}

void Cell::setBoxNum(int bNum)
{
	boxNum = bNum;
}

void Cell::setRowNum(int rNum)
{
	rowNum = rNum;
}

void Cell::setColNum(int cNum)
{
	colNum = cNum;
}

vector<int> Cell::getPossibilities()
{
	return possibilities;
}

int Cell::getAnswer()
{
	return answer;
}

int Cell::getBoxNum()
{
	return boxNum;
}

int Cell::getRowNum()
{
	return rowNum;
}

int Cell::getColNum()
{
	return colNum;
}

//Here ends the getters and setters ~~~~~~~~~~~~



Cell::Cell() 
{
	//some setup
	answer = 0;

	//fill possibilities
	for (int i = 0; i < 9; i++)
	{
		possibilities.push_back(i+1);
	}
}


Cell::~Cell()
{
}





void Cell::reducePossibilities(int num)
{
	  //removes given int from possibilities vector
	 //tom wrote this, but robin had some say in it
	//aaron also helped, we're a team
	for (int i = 0; i < possibilities.size(); i++)
	{
		if(possibilities[i] == num)
		{
			possibilities.erase(possibilities.begin() + i);
			decide();
		}
	}
}

void Cell::decide()
{
	  //checks if there is one possibility
	 //if so it will set that to the answer

	if(possibilities.size() == 1)
	{
		answer = possibilities[0];
	}
}

void Cell::decide(int newAnswer)
{
	 //sets answer to given int and clears the vector
	answer = newAnswer;
  	for (int i = 0; i < possibilities.size(); i++)
    {
      if (possibilities[i] != answer)
      {
  			possibilities.erase(possibilities.begin() + i);
      }
    }
}


bool Cell::findPossibility(int num)
{
	 //checks if the given num is in the possibilities vector
	for (int i = 0; i < possibilities.size(); i++)
	{
	if (possibilities[i] == num)
		return true;
	}
	return false;
}
