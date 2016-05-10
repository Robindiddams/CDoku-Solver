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

void Group::solveBox()
{  
    int count = 0;
    vector<int> known;
    //get all existing answers
    for (int i = 0; i < 9; i++)
    {
        if (cellArray[i]->getAnswer() == 0)
        {
            cout << "found:" << count << endl; 
            count = count + 1;
            known.push_back(cellArray[i]->getAnswer());

        }
    }

    int weAt;
    bool alone = true;
    for (int i = 0; i < 9; i++)
    {
        //enter a cell
        if (cellArray[i]->getAnswer() == 0)
        {
            //cell is empty
            cout << "found!" << count << endl;
            for (int j = 0; j < known.size(); j++)
            {
                  //look through possibilities in this box
                 //next need to know if known[j] can only
                //exist in this box
                alone = true;

                for (int d = 0; d < 9; d++)
                {
                    //look through other cells for 
                    if ((d != i) && (cellArray[d]->getAnswer() == 0)) //same as above, sorta
                    {
                        //we need to check the val against all the other empty cells' possibilities
                        vector<int> poss;
                        poss = cellArray[d] -> getPossibilities();
                        for(int q = 0; q < poss.size(); q++)
                        {
                            if (known[j] == poss[q])
                            {
                                //holy shit its wrong
                                alone = false;
                            }
                        }
                    }

                }
                if (alone = true)
                {
                    cout << "HOLY SHIT IT WORKED\n";
                    cout << "the answer to this col " << cellArray[i]->getColNum() << " row " << cellArray[i]->getRowNum() << " is " << known[j];
                }
            }

        }
    }
}