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
	void solveBox();

};

#endif