// Programmer: Eli Card
// Pseudonym: Spectral Artist
// Date: July 23, 2020
// File: Day3Solution1.cpp

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <map>
#include <set>
using namespace std;

set< tuple<int, int> > convertToSet(vector< tuple<int, int> > v);

int main()
{
    map<char, int> coordinateTranslator = {
        {'v', -1}, 
        {'^', 1},
        {'<', -1},
        {'>', 1}
    };

    typedef vector< tuple<int, int> > coordinate_tuple;

    coordinate_tuple santaCoordArr1;
    int x1 = 0;
    int y1 = 0;

    coordinate_tuple santaCoordArr2;
    int x2 = 0;
    int y2 = 0;

    coordinate_tuple robotCoordArr3;
    int x3 = 0;
    int y3 = 0;

    santaCoordArr1.push_back( tuple<int, int>(0, 0) );
    santaCoordArr2.push_back( tuple<int, int>(0, 0) );
    robotCoordArr3.push_back( tuple<int, int>(0, 0) );

    fstream infile("Day3Input.txt");

    char a, b;
    while(infile >> a >> b)
    {
        int m = coordinateTranslator[a];
        if (a == '^' || a == 'v')
        {
            y1 += m;
            y2 += m;   
        }
        else if (a == '<' || a == '>')
        {
            x1 += m;
            x2 += m;
        }

        santaCoordArr1.push_back( tuple<int, int>(x1, y1) );
        santaCoordArr2.push_back( tuple<int, int>(x2, y2) );

        int n = coordinateTranslator[b];
        if (b == '^' || b == 'v')
        {
            y1 += n;
            y3 += n;
        }
        else if (b == '<' || b == '>')
        {
            x1 += n;
            x3 += n;
        }

        santaCoordArr1.push_back( tuple<int, int>(x1, y1) );
        robotCoordArr3.push_back( tuple<int, int>(x3, y3) );
    }

    santaCoordArr2.insert(santaCoordArr2.end(), robotCoordArr3.begin(), robotCoordArr3.end());

    set<tuple<int, int>> coordSet1 = convertToSet(santaCoordArr1);
    set<tuple<int, int>> coordSet2 = convertToSet(santaCoordArr2);

    cout << "Santa, without help, visits " << coordSet1.size() << " houses.\n";
    cout << "Santa, with robot's help, visits " << coordSet2.size() << " houses." << endl;
}

set<tuple<int, int>> convertToSet( vector< tuple<int, int> > v){
    set<tuple<int, int>> s(v.begin(), v.end());
    return s;
}
