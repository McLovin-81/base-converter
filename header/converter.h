#ifndef CONVERTER_H
#define CONVERTER_H

#include "number.h"


class Converter
{
    private:
        void convertFromDecimal(Number* numberPtr);
        void convertFromBinary(Number* numberPtr);
        void convertFromHex(Number* numberPtr);
        int convertToInt(std::string num);

    public:
        void convert(Number* numberPtr);
};


#endif // CONVERTER_H