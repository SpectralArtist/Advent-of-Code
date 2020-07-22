#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    int count;
    int index = 0;
    bool firstFound = false;
    ifstream infile("Day1Input.txt");

    while(infile >> ch)
    {
        index++;
        if (ch == '(')
        {
            count++;
        }
        else if (ch == ')')
        {
            count--;
        }

        if (!firstFound && count == -1)
        {
            cout << "The first step to cause entry into the basement is " << index << "\n";
            firstFound = true;
        }
    }

    cout << "The final floor is " << count;
}
