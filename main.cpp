#include <iostream>

#include "number.cpp"
#include "converter.cpp"

int main()
{

	Number n("0d1023");
	std::cout << n.getBase() << std::endl;
	std::cout  << n.getValue() << std::endl;
	std::cout << n.baseOk() <<  std::endl;

    Converter converter(&n);

	converter.convertFromDecimal();

	std::cout << "Binary representation: " << n.binaryRepresentation << std::endl;
	std::cout << "Hex representation: " << n.hexRepresensation << std::endl;


	return 0;
}
