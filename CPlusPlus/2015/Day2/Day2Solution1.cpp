// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: July 22, 2020
// File: Day2Solution1.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    ifstream infile("Day2Input.txt");
    string skip;

    int wrappingPaperAmt = 0;
    int ribbonAmt = 0;

    while(infile >> a 
        && getline(infile, skip, 'x')
        && infile >> b
        && getline(infile, skip, 'x')
        && infile >> c
    )
    {
        int arr [3] = {a, b, c};
        sort(arr, arr + 3);

        wrappingPaperAmt += (2 * arr[0] * arr[1]) + (2 * arr[1] * arr[2]) + (2 * arr[0] * arr[2]) + (arr[0] * arr[1]);
        ribbonAmt += (2 * arr[0]) + (2 * arr[1]) + (arr[0] * arr[1] * arr[2]);

    }

    cout << wrappingPaperAmt << endl;
    cout << ribbonAmt << endl;
}
