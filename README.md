# Number Converter

This Number Converter program is designed to convert numbers between different bases: decimal, binary, and hexadecimal. It includes classes for handling numbers and performing conversions.

## Overview

The project consists of two main classes:
- `Number`: Represents a number with a specific base and value.
- `Converter`: Performs conversions between different number bases using the `Number` class.

## Classes

### `Number` Class

#### Constructor
- `Number(std::string n)`: Initializes a Number object with a given value and base.

#### Methods
- `getBase()`: Returns the base of the number.
- `getValue()`: Returns the value of the number.
- `baseOk()`: Checks if the base is valid ('0x', '0b', or '0d').

### `Converter` Class

#### Constructor
- `Converter(Number* numPtr)`: Initializes a Converter object with a pointer to a Number object.

#### Methods
- `convert()`: Performs conversions based on the number's base.
- Conversion methods:
    - `convertFromDecimal()`: Converts from decimal to binary and hexadecimal.
    - `convertFromBinary()`: Converts from binary to decimal and hexadecimal.
    - `convertFromHex()`: Converts from hexadecimal to decimal and binary.
- `convertToInt(std::string num)`: Converts a string number to an integer.

## Usage

### Example

```cpp
#include "number.h"
#include "converter.h"

int main() {
    // Create a Number object
    Number myNumber("0b1010");

    // Create a Converter object with a pointer to 'myNumber'
    Converter converter(&myNumber);

    // Perform conversions
    // (Conversions will be displayed in the console)
    
    return 0;
}

