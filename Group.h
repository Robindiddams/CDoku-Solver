// What: the group class is either a row, box or column, has an array of 9 cells
// Who: Robindiddams, Aaron Hamilton, Tom Reynolds
// Date: April 29, 2017

#ifndef GROUP_H
#define GROUP_H
#include "Cell.h"

#include <iostream>

class Group
{
private:
	Cell *cellArray[9];

public:


	//setters
	void setArray(Cell*[]);
	void setArrVal(int, Cell*);

	//getters
	Cell getCell();
	Cell* getArrVal(int);

	void reduceByNumbers();
	void reduceByCells();


};

#endif