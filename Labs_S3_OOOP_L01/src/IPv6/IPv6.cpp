#include "IPv6.hpp"

IPv6::IPv6(std::string adress)
{
    memset(value, 0, sizeof(value));
    std::stringstream ss(adress);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, ':')) splittedStrings.push_back(item);
    try
    {
        if (splittedStrings.size() != 8) throw std::invalid_argument("");
        //int stringNumber = 0;

        for (int i = 0; i < 8; ++i)
        {
            auto number = std::stoi(splittedStrings[i], 0, 16);
            if (number < 0 || number > 0xFFFF) throw std::invalid_argument("");
            value[i / 2] = BitManipulator::setbits(value[i / 2], number, (1 - (i % 2)) * 16, 16);
        }
    }
    catch (...)
    {
        throw std::invalid_argument("Invalid parse string");
    }
}

IPv6::IPv6(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    memset(value, 0, sizeof(value));
    if (a1 < 0 || a1 > 0xFFFF) throw std::invalid_argument("Invalid a1 argument");
    if (a2 < 0 || a2 > 0xFFFF) throw std::invalid_argument("Invalid a2 argument");
    if (a3 < 0 || a3 > 0xFFFF) throw std::invalid_argument("Invalid a3 argument");
    if (a4 < 0 || a4 > 0xFFFF) throw std::invalid_argument("Invalid a4 argument");
    if (a5 < 0 || a5 > 0xFFFF) throw std::invalid_argument("Invalid a5 argument");
    if (a6 < 0 || a6 > 0xFFFF) throw std::invalid_argument("Invalid a6 argument");
    if (a7 < 0 || a7 > 0xFFFF) throw std::invalid_argument("Invalid a7 argument");
    if (a8 < 0 || a8 > 0xFFFF) throw std::invalid_argument("Invalid a8 argument");
    value[0] = BitManipulator::setbits(value[0], a1, 16, 16);
    value[0] = BitManipulator::setbits(value[0], a2, 0, 16);
    value[1] = BitManipulator::setbits(value[1], a3, 16, 16);
    value[1] = BitManipulator::setbits(value[1], a4, 0, 16);
    value[2] = BitManipulator::setbits(value[2], a5, 16, 16);
    value[2] = BitManipulator::setbits(value[2], a6, 0, 16);
    value[3] = BitManipulator::setbits(value[3], a7, 16, 16);
    value[3] = BitManipulator::setbits(value[3], a8, 0, 16);
}

std::string IPv6::toString()
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(__int16)) << std::hex;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            stream << ((value[i] >> (3 - j) * 8) & 0xFF) << ((j % 2 == 1) ? ":" : "");
    std::string result = std::string(stream.str());
    return result.substr(0, result.size() - 1);;
}
