#include <iostream>

#include "number.cpp"
#include "converter.cpp"

int main()
{

	Number n("0x1234");
	std::cout << n.getBase() << std::endl;
	std::cout  << n.getValue() << std::endl;
	std::cout << n.baseOk() <<  std::endl;


	return 0;
}
