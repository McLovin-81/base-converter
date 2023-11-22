#include <iostream>

#include "number.cpp"
#include "converter.cpp"

int main()
{
	std::string userInput;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Enter: ";
		std::cin >> userInput;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		if (userInput == "exit")
		{
			return 0;
		}

		Number num(userInput);
		Converter converter(&num);
	}

	return 0;
}
