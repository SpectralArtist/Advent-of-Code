// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: October 10, 2020
// File: CharPatternFunctions.cpp

#include <string>

#include "Day5Solution1.h"

bool isCharPair(const char c1, const char c2)
{
    return c1 == c2;
}

bool charIsVowel(const char c1)
{
    bool isVowel = false;

    switch(c1)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            isVowel = true;
    }

    return isVowel;
}

bool isInvalidPair(const char c1, const char c2)
{
    const short SIZE = 4;
    const std::string invalidPairs[SIZE] = {"ab", "cd", "pq", "xy"};

    std::string passedPair = std::string() + c1 + c2;
    bool isInvalidPair = false;

    for (int i = 0; i < SIZE; i++)
    {
        if (!isInvalidPair && invalidPairs[i] == passedPair)
        {
            isInvalidPair = true;
        }
    }

    return isInvalidPair;
}

bool repeatedPairSearch(const std::string pair, const std::string searchStr)
{
    bool hasRepeatedPair = false;

    for (int i = 0; i < searchStr.length() - pair.length() + 1; i++)
    {
        if (!hasRepeatedPair && searchStr.substr(i, pair.length()) == pair)
        {
            hasRepeatedPair = true;
        }
    }

    return hasRepeatedPair;
}

bool areRepeatedCharsWithLetterInBetween(const std::string str)
{
    return str.at(0) == str.at(2);
}