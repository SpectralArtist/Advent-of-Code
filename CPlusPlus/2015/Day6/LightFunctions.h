// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: December 15, 2020
// File: LightFunctions.h

#include <string>

#include "Structs.h"

const short COLS = 1000;

// Desc: The lightInstructionsExecute() changes all elements' statuses within the grid depending on the status passed
//       1) "on" status sets all elements to true
//       2) "off" status sets all elements to false
//       3) "toggle" status sets the opposite of the current element status
void lightInstructionsExecute(short lightsArr[][COLS], box & b, std::string status);

// Desc: The brightnessInstructionsExecute() changes all elements' statuses within the grid depending on the status passed
//       1) "on" status increases all elements by 1
//       2) "off" status decreases all elements by 1
//       3) "toggle" status increases all elements by 2
void brightnessInstructionsExecute(short lightsArr[][COLS], box & b, std::string status);

// Desc: The sumLights() totals up all the elements in the passed array
// Pre: lightsArr[0] ... lightsArr[numRows - 1] must be the rows of data in the passed array
// Post: The total of the elements will be returned
long sumLights(const short lightsArr[][COLS], short numRows);