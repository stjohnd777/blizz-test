//
// Created by Daniel St. John on 3/5/21.
//
//1.Write a function that takes an unsigned integer as input, and returns true if all the digits in the base 10 representation of that number are unique.
//bool AllDigitsUnique(unsigned int value)
//Example:
//AllDigitsUnique(48778584) returns false
//AllDigitsUnique(17308459) returns true
//
#pragma once

namespace dsj {

    namespace optimized {
        unsigned int DigitAt(unsigned long integer, int n);
        bool hasUniqueDigits(unsigned long candidate);
    }

    namespace division {
        unsigned int DigitAt(unsigned long integer);
        unsigned int IntLen(unsigned long integer);
    }

    namespace str {
        unsigned int IntLen(unsigned long integer);
        unsigned int DigitAt(unsigned long integer, int n);
        bool hasUniqueDigits(unsigned long candidate);
    }
}
