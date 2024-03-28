#ifndef NUMBER_H
#define NUMBER_H

#include <string>


class Number
{
    private:
        std::string base;
        std::string value;
        

    public:
        Number(std::string n);
        bool baseOk();

        // Get
        std::string getBase();
        std::string getValue();

        std::string binaryRepresentation;
        std::string hexRepresentation;
        std::string decimalRepresentation;
};

#endif // NUMBER_H
