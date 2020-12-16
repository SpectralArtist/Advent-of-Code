// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: December 15, 2020
// File: Day6Solution1.h

#ifndef STRUCTS_H
#define STRUCTS_H

struct coordinate
{
    short m_xCoord;
    short m_yCoord;
};

struct box
{
    coordinate m_lowerLeft;
    coordinate m_upperRight;
};

#endif