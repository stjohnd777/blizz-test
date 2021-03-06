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
        unsigned int GetDigitAt(unsigned long integer, int n);
        bool IsUniqueDigits(unsigned long candidate);
    }

    namespace division {
        unsigned int GetDigitAt(unsigned long integer);
        unsigned int DigitLength(unsigned long integer);
    }

    namespace str {
        unsigned int DigitLength(unsigned long integer);
        unsigned int GetDigitAt(unsigned long integer, int n);
        bool AtUniqueDigits(unsigned long candidate);
    }
}
