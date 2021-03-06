//
// Created by Daniel St. John on 3/5/21.
//
//1.Write a function that takes an unsigned integer as input, and returns true if all the digits in the base 10 representation of that number are unique.
//bool AllDigitsUnique(unsigned int value)
//Example:
//AllDigitsUnique(48778584) returns false
//AllDigitsUnique(17308459) returns true
//
#include "UniqueDigitsQuestion.h"
#include <algorithm>
#include <iostream>
#include <array>
#include <set>
namespace dsj {

    const unsigned long MAX_BASE10_UNIQUE_DIGITS = 9876543210;


    namespace optimized {

        unsigned int GetDigitAt(unsigned long integer, int n) {

            //static unsigned long tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
            integer = integer / 10 ^ n ; // std::pow(10,n); //tens[n];
            auto digit = (integer % 10);
            return digit;
        }

        bool IsUniqueDigits(unsigned long candidate) {
            //static unsigned long tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
            bool isUniqueSequence = true;
            if (candidate <= 9876543210) {// 9876543210 largest;
                // we have then symbols {0,1...9}, keep a registry if
                // this digit has been observed, initialized to false
                std::array<bool, 10> registry;
                registry.fill(false);
                // loop over each digit
                for (int index = 0; index < 10; index++) {
                    auto integer = candidate / 10 ^ index; //std::pow(10,index) ; //tens[index];
                    if (integer == 0) {
                        // we have run out digits
                        break;
                    }
                    // digit in 10's place
                    auto digit = (integer % 10);
                    if (registry[digit] == false) {
                        registry[digit] = true;
                    } else {
                        // we have see this digit already
                        // we are done
                        isUniqueSequence = false;
                        break;
                    }
                }
            } else {
                isUniqueSequence = false;
            }
            return isUniqueSequence;
        }
    }

    namespace division {

        unsigned int DigitAt(unsigned long integer, int n) {
            for (int index = 0; index < n; index++) {
                integer = integer / 10;
            }
            auto digit = (integer % 10);
            return digit;
        }

        unsigned int DigitLength(unsigned long integer) {
            int len = 1;
            integer = integer / 10;
            while (integer > 0) {
                len++;
                integer = integer / 10;
            }
            return len;
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

        bool AtUniqueDigits(unsigned long candidate) {
            if (candidate > 9876543210) return false;
            auto s = std::to_string(candidate);
            std::set<char> s2(s.begin(), s.end());
            return s.length() == s2.size();
        }
    }
}

