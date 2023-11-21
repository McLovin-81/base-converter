#include <iostream>

#include "number.cpp"
#include "converter.cpp"

int main()
{

	Number n("0d20");
	std::cout << n.getBase() << std::endl;
	std::cout  << n.getValue() << std::endl;
	std::cout << n.baseOk() <<  std::endl;

    Converter converter(&n);

	converter.convertFromDecimal();

	std::cout << "binNum: " << n.binNum << std::endl;


	return 0;
}
