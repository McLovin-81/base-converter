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
        //void setBase(std::string base);
        //void setValue(std::string value);

        // Functions
        bool baseOk();


        std::string binNum;
        std::string hexNum;
        std::string decNum;
};

#endif // NUMBER_H
