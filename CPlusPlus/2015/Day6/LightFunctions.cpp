// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: December 15, 2020
// File: LightFunctions.cpp

#include <iostream>

#include "LightFunctions.h"

void lightInstructionsExecute(short lightsArr[][COLS], box & b, std::string status)
{
    for (int row = b.m_lowerLeft.m_yCoord; row <= b.m_upperRight.m_yCoord; row++)
    {
        for (int col = b.m_lowerLeft.m_xCoord; col <= b.m_upperRight.m_xCoord; col++)
        {
            if (status == "on")
            {
                lightsArr[row][col] = 1;
            }
            else if (status == "off")
            {
                lightsArr[row][col] = 0;
            }
            else if (status == "toggle")
            {
                // Sets element to the opposite state of its current
                // 0 evaluates to false
                // Any other number evaluates to true
                lightsArr[row][col] = (lightsArr[row][col] ? 0 : 1);
            }
        }
    }

    return;
}

void brightnessInstructionsExecute(short lightsArr[][COLS], box & b, std::string status)
{
    for (int row = b.m_lowerLeft.m_yCoord; row <= b.m_upperRight.m_yCoord; row++)
    {
        for (int col = b.m_lowerLeft.m_xCoord; col <= b.m_upperRight.m_xCoord; col++)
        {
            if (status == "on")
            {
                lightsArr[row][col] += 1;
            }
            else if (status == "off")
            {
                // ensures that no element enters negative values
                if (lightsArr[row][col] > 0)
                {
                    lightsArr[row][col] -= 1;
                }
            }
            else if (status == "toggle")
            {
                lightsArr[row][col] += 2;
            }
        }
    }

    return;
}

long sumLights(const short lightsArr[][COLS], short numRows)
{
    long total = 0;
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            total += lightsArr[row][col];
        }
    }

    return total;
}