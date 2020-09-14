#include "IPv4.hpp"

IPv4::IPv4(__int32 value) :value(value) { }

IPv4::IPv4(std::string adress)
{
    value = 0;
    std::stringstream ss(adress);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, '.')) splittedStrings.push_back(item);
    try
    {
        if (splittedStrings.size() != 4) throw std::invalid_argument("");
        for (int i = 0; i < 4; ++i)
        {
            auto number = std::stoi(splittedStrings[i]);
            if (number < 0 || number > 0xFF) throw std::invalid_argument("");
            value = BitManipulator::setbits(value, number, (3 - i) * 8, 8);
        }
    }
    catch (...)
    {
        throw std::invalid_argument("Invalid parse string");
    }
}

IPv4::IPv4(int a1, int a2, int a3, int a4)
{
    value = 0;
    if (a1 < 0 || a1 > 0xFF) throw std::invalid_argument("Invalid a1 argument");
    if (a2 < 0 || a2 > 0xFF) throw std::invalid_argument("Invalid a2 argument");
    if (a3 < 0 || a3 > 0xFF) throw std::invalid_argument("Invalid a3 argument");
    if (a4 < 0 || a4 > 0xFF) throw std::invalid_argument("Invalid a4 argument");
    value = BitManipulator::setbits(value, a1, 24, 8);
    value = BitManipulator::setbits(value, a2, 16, 8);
    value = BitManipulator::setbits(value, a3, 8, 8);
    value = BitManipulator::setbits(value, a4, 0, 8);
}

std::string IPv4::toString()
{
    std::string result;
    for (int i = 0; i < 4; ++i)
        result += std::to_string((value >> (3 - i) * 8) & 0xFF) + ".";
    return result.substr(0, result.size() - 1);
}
