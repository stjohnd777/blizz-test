//
// Created by Daniel St. John on 3/5/21.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../UniqueDigits.h"
#include "TimeMetric.hpp"

#include <iostream>

using namespace std;
using namespace dsj;

TEST_CASE("Test Length Optimized", "[001]") {
    REQUIRE(dsj::optimized::DigitLength(0) == 1);
    REQUIRE(dsj::optimized::DigitLength(3) == 1);
    REQUIRE(dsj::optimized::DigitLength(6) == 1);
    REQUIRE(dsj::optimized::DigitLength(9) == 1);
    REQUIRE(dsj::optimized::DigitLength(12) == 2);
    REQUIRE(dsj::optimized::DigitLength(999) == 3);
    REQUIRE(dsj::optimized::DigitLength(1234) == 4);
    REQUIRE(dsj::optimized::DigitLength(1234567) == 7);
    REQUIRE(dsj::optimized::DigitLength(123456789) == 9);
    REQUIRE(dsj::optimized::DigitLength(1234567890) == 10);
    REQUIRE(dsj::optimized::DigitLength(12345678901) == 11);
    REQUIRE(dsj::optimized::DigitLength(123456789012) == 12);
    REQUIRE(dsj::optimized::DigitLength(1234567890123) == 13);
    REQUIRE(dsj::optimized::DigitLength(12345678901234) == 14);
    REQUIRE(dsj::optimized::DigitLength(123456789012345) == 15);
    REQUIRE(dsj::optimized::DigitLength(1234567890123456) == 16);
    REQUIRE(dsj::optimized::DigitLength(12345678901234567) == 17);
    REQUIRE(dsj::optimized::DigitLength(123456789012345678) == 18);
    REQUIRE(dsj::optimized::DigitLength(1234567890123456789) == 19);
}

TEST_CASE("Test Length String", "[002]") {
    REQUIRE(dsj::str::DigitLength(0) == 1);
    REQUIRE(dsj::str::DigitLength(3) == 1);
    REQUIRE(dsj::str::DigitLength(6) == 1);
    REQUIRE(dsj::str::DigitLength(9) == 1);
    REQUIRE(dsj::str::DigitLength(12) == 2);
    REQUIRE(dsj::str::DigitLength(999) == 3);
    REQUIRE(dsj::str::DigitLength(1234) == 4);
    REQUIRE(dsj::str::DigitLength(1234567) == 7);
    REQUIRE(dsj::str::DigitLength(123456789) == 9);
    REQUIRE(dsj::str::DigitLength(1234567890) == 10);
    REQUIRE(dsj::str::DigitLength(12345678901) == 11);
    REQUIRE(dsj::str::DigitLength(123456789012) == 12);
    REQUIRE(dsj::str::DigitLength(1234567890123) == 13);
    REQUIRE(dsj::str::DigitLength(12345678901234) == 14);
    REQUIRE(dsj::str::DigitLength(123456789012345) == 15);
    REQUIRE(dsj::str::DigitLength(1234567890123456) == 16);
    REQUIRE(dsj::str::DigitLength(12345678901234567) == 17);
    REQUIRE(dsj::str::DigitLength(123456789012345678) == 18);
    REQUIRE(dsj::str::DigitLength(1234567890123456789) == 19);
}

TEST_CASE("Performance Compare DigitLength", "[003]") {

    for (int i = 0; i < 100000; i++) {

        dsj::utils::TimeMetrics::Start("str::DigitLength");
        REQUIRE(dsj::str::DigitLength(1234567890) == 10);
        REQUIRE(dsj::str::DigitLength(12345678901) == 11);
        REQUIRE(dsj::str::DigitLength(123456789012) == 12);
        REQUIRE(dsj::str::DigitLength(1234567890123) == 13);
        REQUIRE(dsj::str::DigitLength(12345678901234) == 14);
        REQUIRE(dsj::str::DigitLength(123456789012345) == 15);
        REQUIRE(dsj::str::DigitLength(1234567890123456) == 16);
        REQUIRE(dsj::str::DigitLength(12345678901234567) == 17);
        REQUIRE(dsj::str::DigitLength(123456789012345678) == 18);
        REQUIRE(dsj::str::DigitLength(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("str::DigitLength");

        dsj::utils::TimeMetrics::Start("division::DigitLength");
        REQUIRE(dsj::optimized::DigitLength(1234567890) == 10);
        REQUIRE(dsj::optimized::DigitLength(12345678901) == 11);
        REQUIRE(dsj::optimized::DigitLength(123456789012) == 12);
        REQUIRE(dsj::optimized::DigitLength(1234567890123) == 13);
        REQUIRE(dsj::optimized::DigitLength(12345678901234) == 14);
        REQUIRE(dsj::optimized::DigitLength(123456789012345) == 15);
        REQUIRE(dsj::optimized::DigitLength(1234567890123456) == 16);
        REQUIRE(dsj::optimized::DigitLength(12345678901234567) == 17);
        REQUIRE(dsj::optimized::DigitLength(123456789012345678) == 18);
        REQUIRE(dsj::optimized::DigitLength(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("division::DigitLength");
    }
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::DigitLength") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::DigitLength") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::DigitLength") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::DigitLength") << std::endl;

    REQUIRE(true == true);
}


TEST_CASE("Get GetDigitAt Optimized ", "[011]") {
    for (auto index = 0; index < 10; index++) {
        cout << "GetDigitAt(9876543210, " << index << ")=" << dsj::optimized::GetDigitAt(9876543210, index) << endl;
        REQUIRE (dsj::optimized::GetDigitAt(9876543210, index) == index);
    }
}

TEST_CASE("Get GetDigitAt String ", "[012]") {
    for (auto index = 0; index < 10; index++) {
        cout << "GetDigitAt(9876543210, " << index << ")=" << dsj::str::GetDigitAt(9876543210, index) << endl;
        REQUIRE (dsj::optimized::GetDigitAt(9876543210, index) == index);
    }
}

TEST_CASE("Performance Compare GetDigitAt", "[013]") {
    for (int i = 0; i < 100000; i++) {

        dsj::utils::TimeMetrics::Start("str::GetDigitAt");
        dsj::optimized::GetDigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("str::GetDigitAt");

        dsj::utils::TimeMetrics::Start("division::GetDigitAt");
        dsj::str::GetDigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("division::GetDigitAt");
    }
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::GetDigitAt") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::GetDigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::GetDigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::GetDigitAt") << std::endl;
}


TEST_CASE("IsUniqueDigits  DivMod ", "[021]") {
    using namespace dsj::optimized;
    REQUIRE(AllDigitsUnique(9876543210) == true);
    REQUIRE(AllDigitsUnique(0) == true);
    REQUIRE(AllDigitsUnique(11) == false);
    REQUIRE(AllDigitsUnique(12) == true);
    REQUIRE(AllDigitsUnique(21) == true);
    REQUIRE(AllDigitsUnique(123) == true);
    REQUIRE(AllDigitsUnique(132) == true);
    REQUIRE(AllDigitsUnique(321) == true);
    REQUIRE(AllDigitsUnique(113) == false);
    REQUIRE(AllDigitsUnique(223) == false);
    REQUIRE(true == true);
}

TEST_CASE("IsUniqueDigits String ", "[022]") {
    using namespace dsj::str;
    REQUIRE(AllDigitsUnique(9876543210) == true);
    REQUIRE(AllDigitsUnique(0) == true);
    REQUIRE(AllDigitsUnique(11) == false);
    REQUIRE(AllDigitsUnique(12) == true);
    REQUIRE(AllDigitsUnique(21) == true);
    REQUIRE(AllDigitsUnique(123) == true);
    REQUIRE(AllDigitsUnique(132) == true);
    REQUIRE(AllDigitsUnique(321) == true);
    REQUIRE(AllDigitsUnique(113) == false);
    REQUIRE(AllDigitsUnique(223) == false);
    REQUIRE(true == true);
}

TEST_CASE("Compare IsUniqueDigits  DivMod vrs String ", "[023]") {

    for (int i = 0; i < 1000000; i++) {
        dsj::utils::TimeMetrics::Start("str");
        dsj::optimized::AllDigitsUnique(i);
        dsj::utils::TimeMetrics::Stop("str");

        dsj::utils::TimeMetrics::Start("opt");
        dsj::str::AllDigitsUnique(i);
        dsj::utils::TimeMetrics::Stop("opt");
    }

    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("opt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("opt") << std::endl;

    cout << "optimized/string : " << (double)dsj::utils::TimeMetrics::TotalTime("opt") /  (double)dsj::utils::TimeMetrics::TotalTime("opt") << endl;
}