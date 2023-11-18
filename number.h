#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number
{
    //private:
    public:
        std::string base;
        std::string number;

    public:
        // Constructor
        Number(std::string n);

        // Get

        // Set
        //void setBaseAndNumber();

        // Functions
        bool checkInput();
        bool checkBase();
};

#endif // NUMBER_H
