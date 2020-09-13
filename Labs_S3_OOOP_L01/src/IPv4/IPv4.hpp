#pragma once
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>

#include "../Helper/BitManipulator.hpp"

class IPv4
{
private:
	__int32 value;
	IPv4(__int32 value);
public:
	IPv4(std::string adress);
	IPv4(int a1, int a2, int a3, int a4);
	std::string toString();
};

