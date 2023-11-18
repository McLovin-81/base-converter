#include <iostream>

#include "number.cpp"

int main()
{
	Number n("0x123");

	std::cout << n.base << std::endl;
	std::cout  << n.number << std::endl;

	return 0;
}
