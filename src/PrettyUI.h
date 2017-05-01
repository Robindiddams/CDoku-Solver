// What: the pretty UI that prompts the user for information in an oldfashioned way
// Who: Robindiddams
// Date: April 29, 2017


#ifndef PRETTYUI_H
#define PRETTYUI_H

#include <iostream>
#include "Puzzle.h"

using namespace std;

int mainMenu();
int answerMenu();
void cellSel(Puzzle* beanss);
void shutDown();
int prettyUI();



#endif
