#include "converter.h"


void Converter::convertFromDecimal()
{
    int numInt;
    int numBinaryInt;

    numInt = convertToInt(number.getValue());

    while (numInt > 0)
    {
        numBinaryInt = numInt % 2;
        number.binNum.insert(0, std::to_string(numBinaryInt));
        numInt = numInt % 2;
    }


}

int Converter::convertToInt(std::string num)
{
    return std::stoi(num);
}