// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: October 10, 2020
// File: Day5Solution1.cpp

#include <iostream>
#include <fstream>
#include <string>

#include "Day5Solution1.h"

// Description: The runPart1() calls the solution calculation for part 1 of day 5
// Pre: none
// Post: Solution to part 1 of day 5 will be output
void runPart1();

// Description: The runPart2() calls the solution calculation for part 2 of day 5
// Pre: none
// Post: Solution to part 2 of day 5 will be output
void runPart2();

int main()
{
    runPart1();
    runPart2();

    return 0;
}

void runPart1()
{
    const short VOWELS_NEEDED_IN_STR = 3;

    short numValidStrs = 0;

    bool hasCharPair;
    bool containsNeededVowels;
    bool hasInvalidPair;

    short numVowelsInStr;

    std::fstream infile("Day5Input.txt");
    std::string input;

    char c1;
    char c2;
    

    while(infile >> input)
    {
        numVowelsInStr = 0;

        hasCharPair = false;
        containsNeededVowels = false;
        hasInvalidPair = false;

        numVowelsInStr += charIsVowel(input.at(input.length() - 1));

        for (short i = 0; i < input.length() - 1; i++)
        {
            c1 = input.at(i);
            c2 = input.at(i + 1);

            if (!hasInvalidPair)
            {
                hasInvalidPair = isInvalidPair(c1, c2);

                if (!hasCharPair)
                {
                    hasCharPair = isCharPair(c1, c2);
                }

                if (!containsNeededVowels)
                {
                    numVowelsInStr += charIsVowel(c1);

                    if (numVowelsInStr >= VOWELS_NEEDED_IN_STR)
                    {
                        containsNeededVowels = true;
                    }
                }
            }
        }

        if (!hasInvalidPair && hasCharPair && containsNeededVowels)
        {
            numValidStrs++;
        }
    }

    std::cout << "Number of Valid Strings for Part 1: " << numValidStrs << std::endl;

    return;
}

void runPart2()
{
    const short SIZE_OF_SEARCH_STR = 2;

    short numValidStrs = 0;

    std::fstream infile("Day5Input.txt");
    std::string input;

    std::string pair;
    std::string triplet;
    std::string searchStr;

    bool hasRepeatedPair;
    bool hasRepeatedWithLtrBtwn;

    while(infile >> input)
    {
        hasRepeatedPair = false;
        hasRepeatedWithLtrBtwn = false;

        for (short i = 0; i < input.length() - 2; i++)
        {
            if (i < input.length() - 3 && !hasRepeatedPair)
            {
                pair = input.substr(i, SIZE_OF_SEARCH_STR);
                searchStr = input.substr(i + SIZE_OF_SEARCH_STR, 
                                         input.length() - i - SIZE_OF_SEARCH_STR);
    
                hasRepeatedPair = repeatedPairSearch(pair, searchStr);
            }
            
            if (!hasRepeatedWithLtrBtwn)
            {
                triplet = input.substr(i, 3);
                hasRepeatedWithLtrBtwn = areRepeatedCharsWithLetterInBetween(triplet);
            }
        }

        if (hasRepeatedPair && hasRepeatedWithLtrBtwn)
        {
            numValidStrs++;
        }
    }

    std::cout << "Number of Valid Strings for Part 2: " << numValidStrs << std::endl;

    return;
}