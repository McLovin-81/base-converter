#include "number.h"


/**
 * @brief Set the number.
 * 
 * @param n User number
*/
Number::Number(std::string n)
{
    value = n.substr(2);
    base = n.substr(0, 2);
}


/**
 * @brief Check if the base is 0x or 0b or a number between 0 and 9.
 * 
 * @return bool
*/
bool Number::baseOk()
{
    if (base == "0x" || base == "0b" || base == "0d")
    {
        return true;
    }
    else
    {
        return false;
    }
}


std::string Number::getBase()
{
    return base;
}


std::string Number::getValue()
{
    return value;
}


/*
void Number::setBase(std::string base)
{
    this->base = base;
}

void Number::setValue(std::string value)
{
    this->value = value;
}
*/