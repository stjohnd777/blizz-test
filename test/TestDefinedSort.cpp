//
// Created by Daniel St. John on 3/5/21.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../question2/DefinedSort.h"
#include "utils/TimeMetric.hpp"

#include <iostream>

using namespace std;
using namespace dsj;

TEST_CASE("Test 1 SortBy(` isetlgornh`)", "[001]") {
    string inputStr =  "sort the letters in this string";
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;
    REQUIRE(inputStr == "     iiisssseeettttttlgorrrnnhh");
}


TEST_CASE("Test Empty", "[002]") {
    string inputStr =  "";
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;
    REQUIRE(inputStr == "");
}

TEST_CASE("Test Undefined", "[003]") {
    string inputStr ;
    string sortBy = " isetlgornh";
    SortLetters(inputStr, sortBy);
    cout << inputStr << endl;
    REQUIRE(inputStr == "");
}

//
//TEST_CASE("Test reverse", "[003]") {
//    string inputStr ;
//    string sortBy = "0123456789abcdefghijklmnopqrstuvwxyz";
//    std::reverse(std::begin(sortBy), std::end(sortBy));
//    SortLetters(inputStr, sortBy);
//    cout << inputStr << endl;
//    REQUIRE(inputStr == "");
//}