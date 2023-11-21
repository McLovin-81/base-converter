#ifndef CONVERTER_H
#define CONVERTER_H

#include "string"

#include "number.h"

class Converter
{
    private:
        Number* numberPtr;

    public:
        Converter(Number* numPtr);
        void convertFromDecimal();
        void convertFromBinary();
        int convertToInt(std::string num);
        void convert();


};


#endif // CONVERTER_H