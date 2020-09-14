#pragma once
#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <iomanip>

#include "../Helper/BitManipulator.hpp"

class IPv6
{
private:
	__int32 value[4];
	IPv6(__int32 value[4]);
public:
	IPv6(std::string adress);
	IPv6(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
	std::string toString();
};

