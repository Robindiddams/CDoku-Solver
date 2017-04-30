// What: the group class is either a row, box or column, has an array of 9 cells, it is pointed to in groups
// Who: Robindiddams, Aaron Hamilton, Tom Reynolds
// Date: April 29, 2017

#include "Group.h"


//Here begins the getters and setters ~~~~~~~~~~~~
//Aaron wrote these
void Group::setArray(Cell *arr[])
{
	*cellArray[9] = *arr[9];
}

void Group::setArrVal(int place, Cell *val)
{
	cellArray[place] = val;
}

Cell Group::getCell()
{
	return *cellArray[9];
}

Cell* Group::getArrVal(int place)
{
	return cellArray[place];
}

//Here ends the getters and setters ~~~~~~~~~~~~



void Group::reduceByNumbers()
{
			 //most powerful and functional algorithm
			//compares the answers of cells in a group 
		 //to then reduce possibilities.
		//tom wrote this


	for (int i = 0; i < 9; i++)
	{
		if (cellArray[i]->getAnswer() != 0)
			{
					for (int j = 0; j < 9; j++)
				{
						if(j != i)
					{
						cellArray[j]->reducePossibilities(cellArray[i]->getAnswer());
					}
				}
			}
		}
}


void Group::reduceByCells()
{
			 //checks the groups around this group for
			//if a value exists and if it does not, it
		 //puts it there
		//tom wrote this
		int index;
		int count;
		for (int i = 1; i < 9; i ++) // iterates through possibilities
				{
				for (int j = 0; j < 9; j++)
				{
						if (cellArray[j]->findPossibility(i) == false) 
						{
								count++;
						}
						else
						{
								index = j; 
						}
				}
				if (count = 8)
				{
				// cellArray[index]->decide(i);
				}
				count = 0;
		}
}
