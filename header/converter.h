#ifndef CONVERTER_H
#define CONVERTER_H

// #include "string"

#include "number.h"


class Converter
{
    private:
        Number* numberPtr;
        void convert();
        void convertFromDecimal();
        void convertFromBinary();
        void convertFromHex();
        int convertToInt(std::string num);

    public:
        Converter(Number* numPtr);
};


#endif // CONVERTER_H