#include "converter.h"

// Constructor
Converter::Converter(Number *numPtr) : numberPtr(numPtr) {}


void Converter::convertFromDecimal()
{
    int numInt;
    int numBinaryInt;

    numInt = convertToInt(numPtr->getValue());

    while (numInt > 0)
    {
        numBinaryInt = numInt % 2;
        numPtr->binNum.insert(0, std::to_string(numBinaryInt));
        numInt = numInt % 2;
    }

}

int Converter::convertToInt(std::string* num)
{
    return std::stoi(*num);
}