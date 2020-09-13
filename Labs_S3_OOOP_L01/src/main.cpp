#include <iostream>

#include "IPv4/IPv4.hpp"


int main()
{
	auto ip1 = IPv4(192, 168, 0, 1);
	auto pi1 = ip1.toString();

	auto ip2 = IPv4("192.168.0.1");
	auto pi2 = ip2.toString();
	std::cout << pi1 << " " << pi2 << std::endl;
}