#ifndef CONVERTER_H
#define CONVERTER_H

#include "string"

#include "number.h"

class Converter
{
    private:
        Number number;


    public:
        void convertFromDecimal();
        int convertToInt(std::string num);


};



#endif // CONVERTER_H