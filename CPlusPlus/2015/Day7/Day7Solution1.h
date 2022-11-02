#include <map>
#include <string>

void splitWireString(const std::string & origStr, 
                 std::string & sub1, 
                 std::string & sub2);

std::string connectWires(const std::map<std::string, std::string> & wires, std::string initWire);

bool isCommand(const std::string & str);

std::string readCommand(std::string & command);

std::string convertBinary(const std::string & str);

int convertToDecimal(const std::string & str);

short convertToNumber(const std::string & str);

std::string notCommand(std::string str);

std::string andCommand(std::string str1, std::string str2);

std::string orCommand(std::string str1, std::string str2);

std::string lShiftCommand(std::string str, int num);

std::string rShiftCommand(std::string str, int num);

#include "Day7Solution1.hpp"