#ifndef CONVERTER_H
#define CONVERTER_H

#include "string"

#include "number.h"

class Converter
{
    private:
        Number* numberPtr;
        int num;


    public:
        Converter(Number* numPtr);
        void convertFromDecimal();
        int convertToInt(std::string num);
        void convert();


};


#endif // CONVERTER_H