#include <iostream>

#include "number.cpp"
#include "converter.cpp"

int main()
{

	Number n("0d255");
    Converter converter(&n);

	std::cout  << n.getValue() << std::endl;
	converter.convert();

	

	return 0;
}
