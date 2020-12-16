// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: December 15, 2020
// File: Day6Solution1.cpp

#include <iostream>
#include <fstream>
#include <string>

#include "Structs.h"
#include "LightFunctions.h"

// Desc: The << overload for box structs that allows the stream output of a box
std::ostream & operator << (std::ostream & out, box & b);

int main()
{
    // size of the grid allowed
    const short ROWS = 1000;
    const short COLS = 1000;

    short lightsArr[ROWS][COLS] = {0};
    short brightnessArr[ROWS][COLS] = {0};

    box inBox;

    std::fstream infile("Day6Input.txt");
    std::string initialCommand;

    // junk holders for file parsing
    char junkChar;
    std::string junkString;

    while(infile >> initialCommand)
    {
        if (initialCommand == "turn")
        {
            infile >> initialCommand;
        }

        // input of the current instruction box
        infile >> inBox.m_lowerLeft.m_xCoord >> junkChar >> inBox.m_lowerLeft.m_yCoord >> junkString
               >> inBox.m_upperRight.m_xCoord >> junkChar >> inBox.m_upperRight.m_yCoord;

        std::cout << initialCommand << " " << inBox << std::endl;

        lightInstructionsExecute(lightsArr, inBox, initialCommand);
        brightnessInstructionsExecute(brightnessArr, inBox, initialCommand);
    }

    // outputs of both parts solutions
    std::cout << "Part 1: Number of lights on is " << sumLights(lightsArr, ROWS) << std::endl;
    std::cout << "Part 2: Total brightness of all the lights is " << sumLights(brightnessArr, ROWS) << std::endl;

    return 0;
}

std::ostream & operator << (std::ostream & out, box & b)
{
    out << "(" << b.m_lowerLeft.m_xCoord << ", " << b.m_lowerLeft.m_yCoord << ")"
        << " -> (" << b.m_upperRight.m_xCoord << ", " << b.m_upperRight.m_yCoord << ")";

    return out;
}
