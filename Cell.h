// What: The cell class has a vector of possible ints that it could be, and identifiers for what it belongs to
// Who: Robindiddams
// Date: April 29, 2017

#ifndef CELL_H
#define CELL_H

#include <vector>
#include <iostream>

using namespace std;

class Cell
{
private:

	vector<int> possibilities;
	int answer;
	int boxNum, rowNum, colNum;

public:
	//constructor
	Cell();


	//function prototype that decides what value to put
	void decide();
	void decide(int);

	//function prototype for function that reduces number of possibilities
	void reduce(vector<int>);

	//setters
	void setAnswer(int);
	void setBoxNum(int);
	void setRowNum(int);
	void setColNum(int);

	//getters
	vector<int> getPossibilities();
	int getAnswer();
	int getBoxNum();
	int getRowNum();
	int getColNum();

	void reduceByNumbers();
	void reducePossibilities(int);
	bool findPossibility(int);

	//Destructor
	~Cell();
};

#endif