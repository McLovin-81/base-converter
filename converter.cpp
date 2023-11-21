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


void Converter::convertFromDecimal()
{
    int numInt;
    int numBinaryInt;

    numInt = convertToInt(numberPtr->getValue());

    while (numInt > 0)
    {
        numBinaryInt = numInt % 2;
        numberPtr->binNum.insert(0, std::to_string(numBinaryInt));
        numInt = numInt % 2;
    }

}

int Converter::convertToInt(std::string num)
{
    return std::stoi(num);
}