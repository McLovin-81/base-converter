#include <iostream>

#include "src/number.cpp"
#include "src/converter.cpp"

int main()
{
	std::string userInput;
	Converter converter;

	while (true)
	{
		std::cout << std::endl;
		std::cout << "Enter: ";
		std::cin >> userInput;
		std::cout << std::endl;

		if (userInput == "exit")
		{
			std::cout << "Exiting the program." << std::endl;
			break;
		}

		Number num(userInput);

		if (num.baseOk())
		{
			converter.convert(&num);
		}
		else
		{
			std::cout << "Invalid number base." << std::endl;
		}
	}

	return 0;
}