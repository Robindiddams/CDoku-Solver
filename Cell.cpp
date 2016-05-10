#include "Cell.h"

//Here begins the getters and setters ~~~~~~~~~~~~
//Aaron wrote these
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

int Cell::getPossSize()
{
	return possibilities.size();
}

//Here ends the getters and setters ~~~~~~~~~~~~



Cell::Cell() 
{
	 //some setup
	//written by robin
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
	//tom wrote this

	if(possibilities.size() == 1)
	{
		answer = possibilities[0];
	}
}

void Cell::decide(int newAnswer)
{
	 //sets answer to given int and clears the vector
	//tom wrote this
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
	//tom wrote this
	for (int i = 0; i < possibilities.size(); i++)
	{
	if (possibilities[i] == num)
		return true;
	}
	return false;
}
