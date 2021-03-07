//
// Created by Daniel St. John on 3/5/21.
//
//1.Write a function that takes an unsigned integer as input, and returns true if all the digits in the base 10 representation of that number are unique.
//bool AllDigitsUnique(unsigned int value)
//Example:
//AllDigitsUnique(48778584) returns false
//AllDigitsUnique(17308459) returns true
//
#include "UniqueDigits.h"
#include <algorithm>
#include <iostream>
#include <array>
#include <set>

namespace dsj {

    const unsigned long MAX_BASE10_UNIQUE_NUM = 9876543210;

    namespace optimized {

        // used internally to above power call
        static unsigned long tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
                                       10000000000};

        /**
         * Get the nth signifigant digit of the number, for example
         * GetDigitAt(42,0) return 2 and GetDigitAt(42,1) return 4 and then
         * for out of range is has been determined to return 0;
         *
         * @param integer
         * @param n
         * @return
         */
        inline unsigned int GetDigitAt(unsigned long integer, int n) {
            integer = integer / tens[n];
            if (integer == 0) return 0;
            auto digit = (integer % 10);
            return digit;
        }

        /**
         * The analogy to string length for integer, for example 42 return 2 and
         * 9876543210 return 10
         *
         * @param integer
         * @param n
         * @return
         */
        inline unsigned int DigitLength(unsigned long integer) {
            int len = 1;
            integer = integer / 10;
            while (integer > 0) {
                len++;
                integer = integer / 10;
            }
            return len;
        }

        /**
         * If all the digit in the number are unique return true otherwise false
         *  * Example:
         *  AllDigitsUnique(48778584) returns false
         *  AllDigitsUnique(17308459) returns true
         * @param candidate
         * @return
         */
        bool AllDigitsUnique(unsigned long candidate) {
            bool isUniqueSequence = true;
            if (candidate <= MAX_BASE10_UNIQUE_NUM) {
                auto digitLen = DigitLength(candidate);
                // keep a registry digits observed
                std::array<bool, 10> registry;
                registry.fill(false);
                // loop over each digit
                for (int index = 0; index < digitLen; index++) {
                    auto digit = GetDigitAt(candidate,index);
                    if (registry[digit] == false) {
                        registry[digit] = true;
                    } else {
                        // we have see this digit already
                        isUniqueSequence = false;
                        break;
                    }
                }
            } else {
                // greater then 9876543210 has duplicate digits base 10
                isUniqueSequence = false;
            }
            return isUniqueSequence;
        }
    }

    namespace str {

        unsigned int DigitLength(unsigned long integer) {
            auto s = std::to_string(integer);
            return s.length();
        }

        unsigned int GetDigitAt(unsigned long integer, int n) {
            auto s = std::to_string(integer);
            reverse(s.begin(), s.end());
            return (s[n] - 48);
        }

        bool AllDigitsUnique(unsigned long candidate) {
            if (candidate > MAX_BASE10_UNIQUE_NUM) return false;
            auto s = std::to_string(candidate);
            std::set<char> s2(s.begin(), s.end());
            return s.length() == s2.size();
        }
    }
}

