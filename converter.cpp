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
Converter::Converter(Number *numPtr) : numberPtr(numPtr)
{
    convert();
}


void Converter::convert()
{
    if (numberPtr->getBase() == "0d")
    {
        convertFromDecimal();
        std::cout << "Binary representation: " << numberPtr->binaryRepresentation << std::endl;
        std::cout << "Hex representation: " << numberPtr->hexRepresensation << std::endl;
    }
    else if (numberPtr->getBase() == "0b")
    {
        convertFromBinary();
        std::cout << "Decimal representation: " << numberPtr->decimalRepresentation << std::endl;
        std::cout << "Hex representation: " << numberPtr->hexRepresensation << std::endl;
    }
    else if(numberPtr->getBase() == "0x")
    {
        convertFromHex();
        std::cout << "Decimal representation: " << numberPtr->decimalRepresentation << std::endl;
        std::cout << "Binary representation: " << numberPtr->binaryRepresentation << std::endl;
    }
}


void Converter::convertFromDecimal()
{
    int numInt;
    int remainder;
    numInt = convertToInt(numberPtr->getValue());

    // To binary //
    while (numInt > 0)
    {
        remainder = numInt % 2;
        numberPtr->binaryRepresentation.insert(0, std::to_string(remainder));
        numInt = numInt / 2;
    }

    // To hexadecimal //
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
                break;
            case 11:
                numberPtr->hexRepresensation.insert(0, "B");
                break;
            case 10:
                numberPtr->hexRepresensation.insert(0, "A");
                break;
            default:
                numberPtr->hexRepresensation.insert(0, std::to_string(remainder));
                break;
        }
        numInt = numInt / 16;
    }
}


void Converter::convertFromBinary()
{
    std::string number = numberPtr->getValue();
    int numLength = numberPtr->getValue().size();;
    int countPower = 1;
    int numTemp = 0;

    // To decimal //
    for (int i = numLength -1; i >= 0; i--)
    {
        if (number[i] == '1')
        {
            numTemp += countPower;
        }
        countPower *= 2;
    }
    numberPtr->decimalRepresentation = std::to_string(numTemp);


    // To hexadecimal //
    int nibbleCounter = 1;
    countPower = 1;
    numTemp = 0;

    for (int i = numLength -1; i >= 0; i--)
    {
        if (number[i] == '1')
        {
            numTemp += countPower;
        }
        countPower *= 2;

        if (nibbleCounter == 4 || i == 0)
        {
            switch (numTemp)
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
                    break;
                case 11:
                    numberPtr->hexRepresensation.insert(0, "B");
                    break;
                case 10:
                    numberPtr->hexRepresensation.insert(0, "A");
                    break;
                default:
                    numberPtr->hexRepresensation.insert(0, std::to_string(numTemp));
                    break;
            }       

            nibbleCounter = 1;
            countPower = 1;
            numTemp = 0;
        }
        else
        {
            nibbleCounter++;
        }
    }
}


void Converter::convertFromHex()
{
    std::string number = numberPtr->getValue();
    int numLength = numberPtr->getValue().size();;
    int countPower = 1;
    long long numTemp = 0;
    int charToInt;

    // To decimal //
    for (int i = numLength -1; i >= 0; i--)
    {
        if (number[i] != '0')
        {
            switch (number[i])
            {
                case 'f':
                    numTemp += 15 * countPower;
                    break;
                case 'e':
                    numTemp += 14 * countPower;
                    break;
                case 'd':
                    numTemp += 13 * countPower;
                    break;
                case 'c':
                    numTemp += 12 * countPower;
                    break;
                case 'b':
                    numTemp += 11 *  countPower;
                    break;
                case 'a':
                    numTemp += 10 * countPower;
                    break;
                case '9':
                case '8':
                case '7':
                case '6':
                case '5':
                case '4':
                case '3':
                case '2':
                case '1':
                    charToInt = number[i] - '0'; // Convert char to int.
                    numTemp += charToInt * countPower;
                    break;
                default:
                    std::cout << "Error" << std::endl;
                    return;
            }
        }
        countPower *= 16;
    }
    numberPtr->decimalRepresentation = std::to_string(numTemp);


    // To binary //
    int remainder;
    std::string binaryNibble;
    int nibbleCounter = 1;

    for (int i = numLength -1; i >= 0; i--)
    {
        if (number[i] != '0')
        {
            switch (number[i])
            {
                case 'f':
                    charToInt = 15;
                    break;
                case 'e':
                    charToInt = 14;
                    break;
                case 'd':
                    charToInt = 13;
                    break;
                case 'c':
                    charToInt = 12;
                    break;
                case 'b':
                    charToInt = 11;
                    break;
                case 'a':
                    charToInt = 10;
                    break;
                case '9':
                case '8':
                case '7':
                case '6':
                case '5':
                case '4':
                case '3':
                case '2':
                case '1':
                    charToInt = number[i] - '0'; // Convert char to int.
                    break;
                default:
                    std::cout << "Error" << std::endl;
                    return;
            }

            while (charToInt > 0)
            {
                remainder = charToInt % 2;
                binaryNibble.insert(0, std::to_string(remainder));
                charToInt /= 2;
            }
            while (binaryNibble.size() < 4)
            {
                binaryNibble.insert(0, "0");
            }
            numberPtr->binaryRepresentation.insert(0, binaryNibble);
            binaryNibble = "";
        }
    }
}


int Converter::convertToInt(std::string num)
{
    return std::stoi(num);
}
