#include <iostream>

#include "number.cpp"
#include "converter.cpp"

int main()
{
	// Hex -> Bin
	Number n("0x14");
    Converter converter(&n);

	std::cout  << "Hex: " << n.getValue() << std::endl;

	return 0;
}
