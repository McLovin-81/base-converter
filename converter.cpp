#include "converter.h"


void Converter::convertFromDecimal()
{
    int numInt;
    int remainder;
    int numBinary;

    numInt = std::stoi(num.getNumber());

    remainder = numInt % 2;
    numInt = numInt / 2;
}