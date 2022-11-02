void splitWireString(const std::string & origStr, 
                 std::string & sub1, 
                 std::string & sub2)
{
    short pos = origStr.find(" -> ");
    sub1 = origStr.substr(0, pos);
    sub2 = origStr.substr(pos + 4);

    return;
}

std::string connectWires(const std::map<std::string, std::string> & wires, std::string initWire)
{
    const short NUM_ASCII_NUMBERS = 48;
    std::string wire = wires.at(initWire);
    std::string commandType;

    if (isCommand(wire))
    {
        commandType = readCommand(wire);

        if (commandType == "NOT")
        {
            return notCommand(connectWires(wires, wire));
        }
        else if (commandType == "AND")
        {
            return andCommand(
                              connectWires(wires, wire.substr(0, wire.find(','))),
                              connectWires(wires, wire.substr(wire.find(',') + 1))
                             );
        }
        else if (commandType == "OR")
        {
            return orCommand(
                             connectWires(wires, wire.substr(0, wire.find(','))),
                             connectWires(wires, wire.substr(wire.find(',') + 1))
                            );
        }
        else if (commandType == "LSHIFT")
        {
            return lShiftCommand(
                                 connectWires(wires, wire.substr(0, wire.find(','))),
                                 convertToNumber(wire.substr(wire.find(',') + 1))
                                );
        }
        else if (commandType == "RSHIFT")
        {
            return rShiftCommand(
                                 connectWires(wires, wire.substr(0, wire.find(','))),
                                 convertToNumber(wire.substr(wire.find(',') + 1))
                                );
        }
        
    }
    else
    {
        return convertBinary(wire);
    }

    return "";
}

bool isCommand(const std::string & str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str.at(i)))
        {
            return true;
        }
    }

    return false;
}

std::string readCommand(std::string & command)
{
    int notPos = command.find("NOT ");
    int andPos = command.find(" AND ");
    int orPos = command.find(" OR ");
    int lShiftPos = command.find(" LSHIFT ");
    int rShiftPos = command.find(" RSHIFT ");

    if (notPos > -1)
    {
        command = command.substr(4);
        return "NOT";
    }
    else if (andPos > -1)
    {
        command = command.substr(0, andPos) + "," + command.substr(andPos + 5);
        return "AND";
    }
    else if (orPos > -1)
    {
        command = command.substr(0, orPos) + "," + command.substr(orPos + 4);
        return "OR";
    }
    else if (lShiftPos > -1)
    {
        command = command.substr(0, lShiftPos) + "," + command.substr(lShiftPos + 8);
        return "LSHIFT";
    }
    else if (rShiftPos > -1)
    {
        command = command.substr(0, rShiftPos) + "," + command.substr(rShiftPos + 8);
        return "RSHIFT";
    }
    
    return "";
}

std::string convertBinary(const std::string & str)
{
    short num = convertToNumber(str);
    std::cout << num << std::endl;
    std::string binStr = "";
    
    while (num > 0)
    {
        if (num % 2 == 0)
        {
            binStr.insert(0, 1, '0');
        }
        else 
        {
            binStr.insert(0, 1, '1');
        }

        num /= 2;
    }

    binStr.insert(0, 16 - binStr.length(), '0');

    std::cout << binStr << std::endl;

    return binStr;
}

int convertToDecimal(const std::string & str)
{
    const short NUM_ASCII_NUMBERS = 48;
    int sum = 0;
    const int MULT = 2;
    int digit = 1;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        sum += (static_cast<int>(str[i]) - NUM_ASCII_NUMBERS) * digit;
        digit *= MULT;
    }

    return sum;
}

short convertToNumber(const std::string & str)
{
    const short NUM_ASCII_NUMBERS = 48;
    int sum = 0;
    const int MULT = 10;
    int digit = 1;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        sum += (static_cast<int>(str[i]) - NUM_ASCII_NUMBERS) * digit;
        digit *= MULT;
    }

    return sum;
}

std::string notCommand(std::string str)
{
    std::string notStr = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            notStr.push_back('1');
        }
        else
        {
            notStr.push_back('0');
        }
    }

    return notStr;
}

std::string andCommand(std::string str1, std::string str2)
{
    std::string andStr = "";

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == '1' && str2[i] == '1')
        {
            andStr.push_back('1');
        }
        else
        {
            andStr.push_back('0');
        }
    }
    
    return andStr;
}

std::string orCommand(std::string str1, std::string str2)
{
    std::string orStr = "";

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == '1' || str2[i] == '1')
        {
            orStr.push_back('1');
        }
        else
        {
            orStr.push_back('0');
        }
    }
    
    return orStr;
}

std::string lShiftCommand(std::string str, int num)
{
    str.erase(0, num);
    str.insert(str.end(), num, '0');
    
    return str;
}

std::string rShiftCommand(std::string str, int num)
{
    str.erase(str.length() - num - 1, num);
    str.insert(0, num, '0');
    
    return str;
}
