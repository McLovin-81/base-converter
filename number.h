#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number
{
    //private:
    private:
        std::string base;
        std::string number;

    public:
        // Constructor
        Number(std::string n);

        // Get

        // Set

        // Functions
        bool baseOk();
        std::string getBase();
        std::string getNumber();
};

#endif // NUMBER_H
