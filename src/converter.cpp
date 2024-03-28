#include "../header/converter.h"


void Converter::convert(Number* numberPtr)
{
    if (numberPtr->getBase() == "0d")
    {
        std::cout << "Decimal: " << numberPtr->getValue() << std::endl;
        convertFromDecimal(numberPtr);
        std::cout << "Binary representation: " << numberPtr->binaryRepresentation << std::endl;
        std::cout << "Hex representation: " << numberPtr->hexRepresentation << std::endl;
    }
    else if (numberPtr->getBase() == "0b")
    {
        std::cout << "Binary: " << numberPtr->getValue() << std::endl;
        convertFromBinary(numberPtr);
        std::cout << "Decimal representation: " << numberPtr->decimalRepresentation << std::endl;
        std::cout << "Hex representation: " << numberPtr->hexRepresentation << std::endl;
    }
    else if(numberPtr->getBase() == "0x")
    {
        std::cout << "Hex: " << numberPtr->getValue() << std::endl;
        convertFromHex(numberPtr);
        std::cout << "Decimal representation: " << numberPtr->decimalRepresentation << std::endl;
        std::cout << "Binary representation: " << numberPtr->binaryRepresentation << std::endl;
    }
}


void Converter::convertFromDecimal(Number* numberPtr)
{
    int numInt;
    int remainder;
    numInt = convertToInt(numberPtr->getValue());

    // To binary //
    while (numInt > 0)
    {
        remainder = numInt % 2;
        numberPtr->binaryRepresentation.insert(0, std::to_string(remainder));
        numInt /= 2;
    }

    // To hexadecimal //
    numInt = convertToInt(numberPtr->getValue());
    while (numInt > 0)
    {
        remainder = numInt % 16;
        switch (remainder)
        {
            case 15:
                numberPtr->hexRepresentation.insert(0, "F");
                break;
            case 14:
                numberPtr->hexRepresentation.insert(0, "E");
                break;
            case 13:
                numberPtr->hexRepresentation.insert(0, "D");
                break;
            case 12:
                numberPtr->hexRepresentation.insert(0, "C");
                break;
            case 11:
                numberPtr->hexRepresentation.insert(0, "B");
                break;
            case 10:
                numberPtr->hexRepresentation.insert(0, "A");
                break;
            default:
                numberPtr->hexRepresentation.insert(0, std::to_string(remainder));
                break;
        }
        numInt = numInt / 16;
    }
}


void Converter::convertFromBinary(Number* numberPtr)
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
                    numberPtr->hexRepresentation.insert(0, "F");
                    break;
                case 14:
                    numberPtr->hexRepresentation.insert(0, "E");
                    break;
                case 13:
                    numberPtr->hexRepresentation.insert(0, "D");
                    break;
                case 12:
                    numberPtr->hexRepresentation.insert(0, "C");
                    break;
                case 11:
                    numberPtr->hexRepresentation.insert(0, "B");
                    break;
                case 10:
                    numberPtr->hexRepresentation.insert(0, "A");
                    break;
                default:
                    numberPtr->hexRepresentation.insert(0, std::to_string(numTemp));
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


void Converter::convertFromHex(Number* numberPtr)
{
    std::string number = numberPtr->getValue();
    int numLength = number.size();
    int countPower = 1;
    long long numTemp = 0;
    int charToInt;

    // To decimal //
    for (int i = numLength -1; i >= 0; i--)
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
                case '0':
                    charToInt = number[i] - '0'; // Convert a character to an integer by subtracting the ASCII value of '0' from the character.
                    numTemp += charToInt * countPower;
                    break;
                default:
                    std::cout << "Error: Invalid hex digit" << std::endl;
                    return;
            }

        countPower *= 16;
    }
    numberPtr->decimalRepresentation = std::to_string(numTemp);


    // To binary //
    std::string binaryNibble;

    for (int i = numLength - 1; i >= 0; i--)
    {
        switch (number[i])
        {
            case 'f':
                binaryNibble = "1111 ";
                break;
            case 'e':
                binaryNibble = "1110 ";
                break;
            case 'd':
                binaryNibble = "1101 ";
                break;
            case 'c':
                binaryNibble = "1100 ";
                break;
            case 'b':
                binaryNibble = "1011 ";
                break;
            case 'a':
                binaryNibble = "1010 ";
                break;
            case '9':
                binaryNibble = "1001 ";
                break;
            case '8':
                binaryNibble = "1000 ";
                break;
            case '7':
                binaryNibble = "0111 ";
                break;
            case '6':
                binaryNibble = "0110 ";
                break;
            case '5':
                binaryNibble = "0101 ";
                break;
            case '4':
                binaryNibble = "0100 ";
                break;
            case '3':
                binaryNibble = "0011 ";
                break;
            case '2':
                binaryNibble = "0010 ";
                break;
            case '1':
                binaryNibble = "0001 ";
                break;
            case '0':
                binaryNibble = "0000 ";
                break;
        }
        numberPtr->binaryRepresentation.insert(0, binaryNibble);
    }
}


int Converter::convertToInt(std::string num)
{
    return std::stoi(num);
}
