#include <iostream>

#include "IPv4/IPv4.hpp"
#include "IPv6/IPv6.hpp"


int main()
{
	auto ip1 = IPv4(192, 168, 0, 1);
	auto pi1 = ip1.toString();

	auto ip2 = IPv4("192.168.0.1");
	auto pi2 = ip2.toString();
	std::cout << pi1 << " " << pi2 << std::endl;

	auto ipv6 = IPv6("0011:2233:4A55:6677:8899:aabb:ccdd:eeff");
	auto ipv62 = IPv6(0x0011, 0x2233, 0x4455, 0x6677, 0x8899, 0xaabb, 0xccdd, 0xeeff);
	auto str = ipv62.toString();
	std::cout << str << std::endl;
}