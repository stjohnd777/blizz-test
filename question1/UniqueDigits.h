//
// Created by Daniel St. John on 3/5/21.
//

/*
 *
 * Write a function that takes an unsigned integer as input, and returns true if all the digits in the
 * base 10 representation of that number are unique.
 *
 * bool AllDigitsUnique(unsigned int value)
 *
 * Example:
 *  AllDigitsUnique(48778584) returns false
 *  AllDigitsUnique(17308459) returns true
*/

#pragma once

namespace dsj {

    /**
     * This is more performant implementation
     */
    namespace optimized {
        /**
         * Get the nth signifigant digit of the number, for example
         * GetDigitAt(42,0) return 2 and GetDigitAt(42,1) return 4 and then
         * for out of range is has been determined to return 0;
         *
         * @param integer
         * @param n
         * @return
         */
        unsigned int GetDigitAt(unsigned long integer, int n);
        /**
         * The analogy to string length for integer, for example 42 return 2 and
         * 9876543210 return 10
         *
         * @param integer
         * @param n
         * @return
         */
        unsigned int DigitLength(unsigned long integer);
        //bool IsNumberComposedUniqueDigits(unsigned long candidate);
        /**
         * If all the digit in the number are unique return true otherwise false
         *  * Example:
         *  AllDigitsUnique(48778584) returns false
         *  AllDigitsUnique(17308459) returns true
         * @param candidate
         * @return
         */
        bool AllDigitsUnique(unsigned long candidate);
    }

    /**
     * This is a readable simple implementation using string,
     * not intended as usable for performance intense requirements
     */
    namespace str {
        unsigned int GetDigitAt(unsigned long integer, int n);
        unsigned int DigitLength(unsigned long integer);
        bool AllDigitsUnique(unsigned long candidate);
    }
}
