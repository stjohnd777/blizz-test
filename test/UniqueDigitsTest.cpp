//
// Created by Daniel St. John on 3/5/21.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../UniqueDigitsQuestion.h"
#include "TimeMetric.hpp"

#include <iostream>

using namespace std;
using namespace dsj;

TEST_CASE("Test Length Div", "[001]") {
    REQUIRE(dsj::division::IntLen(0) == 1);
    REQUIRE(dsj::division::IntLen(3) == 1);
    REQUIRE(dsj::division::IntLen(6) == 1);
    REQUIRE(dsj::division::IntLen(9) == 1);
    REQUIRE(dsj::division::IntLen(12) == 2);
    REQUIRE(dsj::division::IntLen(999) == 3);
    REQUIRE(dsj::division::IntLen(1234) == 4);
    REQUIRE(dsj::division::IntLen(1234567) == 7);
    REQUIRE(dsj::division::IntLen(123456789) == 9);
    REQUIRE(dsj::division::IntLen(1234567890) == 10);
    REQUIRE(dsj::division::IntLen(12345678901) == 11);
    REQUIRE(dsj::division::IntLen(123456789012) == 12);
    REQUIRE(dsj::division::IntLen(1234567890123) == 13);
    REQUIRE(dsj::division::IntLen(12345678901234) == 14);
    REQUIRE(dsj::division::IntLen(123456789012345) == 15);
    REQUIRE(dsj::division::IntLen(1234567890123456) == 16);
    REQUIRE(dsj::division::IntLen(12345678901234567) == 17);
    REQUIRE(dsj::division::IntLen(123456789012345678) == 18);
    REQUIRE(dsj::division::IntLen(1234567890123456789) == 19);
}

TEST_CASE("Test Length String", "[002]") {
    REQUIRE(dsj::str::IntLen(0) == 1);
    REQUIRE(dsj::str::IntLen(3) == 1);
    REQUIRE(dsj::str::IntLen(6) == 1);
    REQUIRE(dsj::str::IntLen(9) == 1);
    REQUIRE(dsj::str::IntLen(12) == 2);
    REQUIRE(dsj::str::IntLen(999) == 3);
    REQUIRE(dsj::str::IntLen(1234) == 4);
    REQUIRE(dsj::str::IntLen(1234567) == 7);
    REQUIRE(dsj::str::IntLen(123456789) == 9);
    REQUIRE(dsj::str::IntLen(1234567890) == 10);
    REQUIRE(dsj::str::IntLen(12345678901) == 11);
    REQUIRE(dsj::str::IntLen(123456789012) == 12);
    REQUIRE(dsj::str::IntLen(1234567890123) == 13);
    REQUIRE(dsj::str::IntLen(12345678901234) == 14);
    REQUIRE(dsj::str::IntLen(123456789012345) == 15);
    REQUIRE(dsj::str::IntLen(1234567890123456) == 16);
    REQUIRE(dsj::str::IntLen(12345678901234567) == 17);
    REQUIRE(dsj::str::IntLen(123456789012345678) == 18);
    REQUIRE(dsj::str::IntLen(1234567890123456789) == 19);
//    REQUIRE(dsj::str::IntLen(12345678901234567890) == 20 );
}

TEST_CASE("Compare Div and String", "[003]") {

    std::array<int, 1000000> iterate;
    std::for_each(begin(iterate), end(iterate), [&](int i) {

        dsj::utils::TimeMetrics::Start("str::IntLen");
        REQUIRE(dsj::str::IntLen(1234567890) == 10);
        REQUIRE(dsj::str::IntLen(12345678901) == 11);
        REQUIRE(dsj::str::IntLen(123456789012) == 12);
        REQUIRE(dsj::str::IntLen(1234567890123) == 13);
        REQUIRE(dsj::str::IntLen(12345678901234) == 14);
        REQUIRE(dsj::str::IntLen(123456789012345) == 15);
        REQUIRE(dsj::str::IntLen(1234567890123456) == 16);
        REQUIRE(dsj::str::IntLen(12345678901234567) == 17);
        REQUIRE(dsj::str::IntLen(123456789012345678) == 18);
        REQUIRE(dsj::str::IntLen(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("str::IntLen");

        dsj::utils::TimeMetrics::Start("division::IntLen");
        REQUIRE(dsj::division::IntLen(1234567890) == 10);
        REQUIRE(dsj::division::IntLen(12345678901) == 11);
        REQUIRE(dsj::division::IntLen(123456789012) == 12);
        REQUIRE(dsj::division::IntLen(1234567890123) == 13);
        REQUIRE(dsj::division::IntLen(12345678901234) == 14);
        REQUIRE(dsj::division::IntLen(123456789012345) == 15);
        REQUIRE(dsj::division::IntLen(1234567890123456) == 16);
        REQUIRE(dsj::division::IntLen(12345678901234567) == 17);
        REQUIRE(dsj::division::IntLen(123456789012345678) == 18);
        REQUIRE(dsj::division::IntLen(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("division::IntLen");
    });
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::IntLen") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::IntLen") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::IntLen") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::IntLen") << std::endl;

    REQUIRE(true == true);
}


TEST_CASE("Get DigitAt DivMod ", "[011]") {
    for (auto index = 0; index < 10; index++) {
        cout << "DigitAt(9876543210, " << index << ")=" << dsj::optimized::DigitAt(9876543210, index) << endl;
        REQUIRE (dsj::optimized::DigitAt(9876543210, index) == index);
    }
}

TEST_CASE("Get DigitAt String ", "[012]") {
    for (auto index = 0; index < 10; index++) {
        cout << "DigitAt(9876543210, " << index << ")=" << dsj::str::DigitAt(9876543210, index) << endl;
        REQUIRE (dsj::optimized::DigitAt(9876543210, index) == index);
    }
}

TEST_CASE("Compare DigitAt DivMode vrs String ", "[013]") {
    std::array<int, 1000000> iterate;
    std::for_each(begin(iterate), end(iterate), [&](int i) {

        dsj::utils::TimeMetrics::Start("str::DigitAt");
        dsj::optimized::DigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("str::DigitAt");

        dsj::utils::TimeMetrics::Start("division::DigitAt");
        dsj::str::DigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("division::DigitAt");
    });
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::DigitAt") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::DigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::DigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::DigitAt") << std::endl;
}


TEST_CASE("hasUniqueDigits  DivMod ", "[021]") {
    using namespace dsj::optimized;
    REQUIRE(hasUniqueDigits(9876543210) == true);
    REQUIRE(hasUniqueDigits(0) == true);
    REQUIRE(hasUniqueDigits(11) == false);
    REQUIRE(hasUniqueDigits(12) == true);
    REQUIRE(hasUniqueDigits(21) == true);
    REQUIRE(hasUniqueDigits(123) == true);
    REQUIRE(hasUniqueDigits(132) == true);
    REQUIRE(hasUniqueDigits(321) == true);
    REQUIRE(hasUniqueDigits(113) == false);
    REQUIRE(hasUniqueDigits(223) == false);
    REQUIRE(true == true);
}

TEST_CASE("hasUniqueDigits String ", "[022]") {
    using namespace dsj::str;
    REQUIRE(hasUniqueDigits(9876543210) == true);
    REQUIRE(hasUniqueDigits(0) == true);
    REQUIRE(hasUniqueDigits(11) == false);
    REQUIRE(hasUniqueDigits(12) == true);
    REQUIRE(hasUniqueDigits(21) == true);
    REQUIRE(hasUniqueDigits(123) == true);
    REQUIRE(hasUniqueDigits(132) == true);
    REQUIRE(hasUniqueDigits(321) == true);
    REQUIRE(hasUniqueDigits(113) == false);
    REQUIRE(hasUniqueDigits(223) == false);
    REQUIRE(true == true);
}

TEST_CASE("Compare hasUniqueDigits  DivMod vrs String ", "[023]") {
    std::array<int, 1000000> iterate;
    std::for_each(begin(iterate), end(iterate), [&](int i) {

        dsj::utils::TimeMetrics::Start("str");
        dsj::optimized::hasUniqueDigits(9876543210);
        dsj::utils::TimeMetrics::Stop("str");

        dsj::utils::TimeMetrics::Start("division");
        dsj::str::hasUniqueDigits(9876543210);
        dsj::utils::TimeMetrics::Stop("division");
    });
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division") << std::endl;
}