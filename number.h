#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number
{
    //private:
    private:
        std::string base;
        std::string value;

    public:
        // Constructor
        Number(std::string n);

        // Get
        std::string getBase();
        std::string getValue();

        // Set

        // Functions
        bool baseOk();


        std::string binaryRepresentation;
        std::string hexRepresensation;
        std::string decimalRepresentation;
};

#endif // NUMBER_H
