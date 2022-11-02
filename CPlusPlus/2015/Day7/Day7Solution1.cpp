#include <map>
#include <string>
#include <fstream>
#include <iostream>

#include "Day7Solution1.h"

int main()
{
    std::map<std::string, std::string> wires;
    const std::string FINAL_WIRE = "y";
    std::string line;
    std::string substr1;
    std::string substr2;

    while (getline(std::cin, line))
    {
        splitWireString(line, substr1, substr2);
        wires[substr2] = substr1;

        std::cout << wires[substr2] << std::endl;
    }

    std::cout << std::endl 
              << convertToDecimal(connectWires(wires, FINAL_WIRE)) << std::endl;

    return 0;
}