//
// Created by Daniel St. John on 3/5/21.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../DefinedSort.h"
#include "TimeMetric.hpp"

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