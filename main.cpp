#include <iostream>

#include "number.cpp"

int main()
{
	Number n("0x1234");

	std::cout << n.base << std::endl;
	std::cout  << n.number << std::endl;

	std::cout << n.baseOk() <<  std::endl;

	return 0;
}
