#include "converter.h"

// Constructor
/**
 * @brief Constructor for the Converter class.
 * 
 * Initializes a Converter object with a pointer to a Number object.
 * 
 * @param numPtr A pointer to a Number object that the Converter will utilize.
 * 
 * @details This constructor initializes the Converter object by setting its internal pointer
 * to a Number object provided as a parameter. The Converter object can then utilize the 
 * Number object via this pointer in various operations or functions.
 * 
 * @note The ownership and lifetime of the Number object pointed to by 'numPtr' 
 * must be managed externally to prevent potential memory leaks or access to invalid objects.
 * 
 * Example Usage:
 * \code{.cpp}
 * Number myNumber("123"); // Create a Number object
 * Converter converter(&myNumber); // Create a Converter object with a pointer to 'myNumber'
 * \endcode
 */
Converter::Converter(Number *numPtr) : numberPtr(numPtr) {}


void Converter::convert()
{
    if (numberPtr->getBase() == "0d")
    {
        convertFromDecimal();
        // Add the other calculations
    }
}

void Converter::convertFromDecimal()
{
    int numInt;
    int remainder;

    numInt = convertToInt(numberPtr->getValue());
    while (numInt > 0)
    {
        remainder = numInt % 2;
        numberPtr->binaryRepresentation.insert(0, std::to_string(remainder));
        numInt = numInt / 2;
    }

    numInt = convertToInt(numberPtr->getValue());
    while (numInt > 0)
    {
        remainder = numInt % 16;
        switch (remainder)
        {
            case 15:
                numberPtr->hexRepresensation.insert(0, "F");
                break;
            case 14:
                numberPtr->hexRepresensation.insert(0, "E");
                break;
            case 13:
                numberPtr->hexRepresensation.insert(0, "D");
                break;
            case 12:
                numberPtr->hexRepresensation.insert(0, "C");
            case 11:
                numberPtr->hexRepresensation.insert(0, "B");
                break;
            case 10:
                numberPtr->hexRepresensation.insert(0, "A");
                break;
            default:
                numberPtr->hexRepresensation.insert(0, std::to_string(remainder));
        }
        numInt = numInt / 16;
    }
}

int Converter::convertToInt(std::string num)
{
    return std::stoi(num);
}