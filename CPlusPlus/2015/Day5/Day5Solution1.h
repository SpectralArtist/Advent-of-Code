// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: October 10, 2020
// File: Day5Solution1.h

#include <string>

// Description: The isCharPair() returns if the two characters passed are the same
// Pre: None
// Post: The equality of the two parameters will be returned
bool isCharPair(const char c1, const char c2);

// Description: The charIsVowel() returns whether or not the passed char is a vowel
// Pre: None
// Post: The state of the char (not) being a variable will be returned
bool charIsVowel(const char c1);

// Description: The isInvalidPair() checks the combined string of the passed chars against
//              an array of invalid pairs and returns if a match is found
// Pre: None
// Post: The bool existance of a match between parameters and any invalid pair will be returned
bool isInvalidPair(const char c1, const char c2);

// Description: The repeatedPairSearch() returns whether or not the pair passed is a sub string
//              of searchStr
// Pre: None
// Post: The bool existance of the pair as a sub string of searchStr will be returned
bool repeatedPairSearch(const std::string pair, const std::string searchStr);

// Description: The areRepeatedCharsWithLetterInBetween() returns whether or not the string contains
//             a letter at the start and end that are the same while also have a single char between them
// Pre: String passed must be of length 3
// Post: The bool of whether the string passes the check detailed in the description will be returned
bool areRepeatedCharsWithLetterInBetween(const std::string str);