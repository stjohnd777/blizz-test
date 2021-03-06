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
    REQUIRE(dsj::division::DigitLength(0) == 1);
    REQUIRE(dsj::division::DigitLength(3) == 1);
    REQUIRE(dsj::division::DigitLength(6) == 1);
    REQUIRE(dsj::division::DigitLength(9) == 1);
    REQUIRE(dsj::division::DigitLength(12) == 2);
    REQUIRE(dsj::division::DigitLength(999) == 3);
    REQUIRE(dsj::division::DigitLength(1234) == 4);
    REQUIRE(dsj::division::DigitLength(1234567) == 7);
    REQUIRE(dsj::division::DigitLength(123456789) == 9);
    REQUIRE(dsj::division::DigitLength(1234567890) == 10);
    REQUIRE(dsj::division::DigitLength(12345678901) == 11);
    REQUIRE(dsj::division::DigitLength(123456789012) == 12);
    REQUIRE(dsj::division::DigitLength(1234567890123) == 13);
    REQUIRE(dsj::division::DigitLength(12345678901234) == 14);
    REQUIRE(dsj::division::DigitLength(123456789012345) == 15);
    REQUIRE(dsj::division::DigitLength(1234567890123456) == 16);
    REQUIRE(dsj::division::DigitLength(12345678901234567) == 17);
    REQUIRE(dsj::division::DigitLength(123456789012345678) == 18);
    REQUIRE(dsj::division::DigitLength(1234567890123456789) == 19);
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
//    REQUIRE(dsj::str::DigitLength(12345678901234567890) == 20 );
}

TEST_CASE("Compare Div and String", "[003]") {

    std::array<int, 1000000> iterate;
    std::for_each(begin(iterate), end(iterate), [&](int i) {

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
        REQUIRE(dsj::division::DigitLength(1234567890) == 10);
        REQUIRE(dsj::division::DigitLength(12345678901) == 11);
        REQUIRE(dsj::division::DigitLength(123456789012) == 12);
        REQUIRE(dsj::division::DigitLength(1234567890123) == 13);
        REQUIRE(dsj::division::DigitLength(12345678901234) == 14);
        REQUIRE(dsj::division::DigitLength(123456789012345) == 15);
        REQUIRE(dsj::division::DigitLength(1234567890123456) == 16);
        REQUIRE(dsj::division::DigitLength(12345678901234567) == 17);
        REQUIRE(dsj::division::DigitLength(123456789012345678) == 18);
        REQUIRE(dsj::division::DigitLength(1234567890123456789) == 19);
        dsj::utils::TimeMetrics::Stop("division::DigitLength");
    });
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::DigitLength") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::DigitLength") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::DigitLength") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::DigitLength") << std::endl;

    REQUIRE(true == true);
}


TEST_CASE("Get GetDigitAt DivMod ", "[011]") {
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

TEST_CASE("Compare GetDigitAt DivMode vrs String ", "[013]") {
    std::array<int, 1000000> iterate;
    std::for_each(begin(iterate), end(iterate), [&](int i) {

        dsj::utils::TimeMetrics::Start("str::GetDigitAt");
        dsj::optimized::GetDigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("str::GetDigitAt");

        dsj::utils::TimeMetrics::Start("division::GetDigitAt");
        dsj::str::GetDigitAt(9876543210, 5);
        dsj::utils::TimeMetrics::Stop("division::GetDigitAt");
    });
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str::GetDigitAt") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division::GetDigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str::GetDigitAt") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division::GetDigitAt") << std::endl;
}


TEST_CASE("IsUniqueDigits  DivMod ", "[021]") {
    using namespace dsj::optimized;
    REQUIRE(IsUniqueDigits(9876543210) == true);
    REQUIRE(IsUniqueDigits(0) == true);
    REQUIRE(IsUniqueDigits(11) == false);
    REQUIRE(IsUniqueDigits(12) == true);
    REQUIRE(IsUniqueDigits(21) == true);
    REQUIRE(IsUniqueDigits(123) == true);
    REQUIRE(IsUniqueDigits(132) == true);
    REQUIRE(IsUniqueDigits(321) == true);
    REQUIRE(IsUniqueDigits(113) == false);
    REQUIRE(IsUniqueDigits(223) == false);
    REQUIRE(true == true);
}

TEST_CASE("IsUniqueDigits String ", "[022]") {
    using namespace dsj::str;
    REQUIRE(AtUniqueDigits(9876543210) == true);
    REQUIRE(AtUniqueDigits(0) == true);
    REQUIRE(AtUniqueDigits(11) == false);
    REQUIRE(AtUniqueDigits(12) == true);
    REQUIRE(AtUniqueDigits(21) == true);
    REQUIRE(AtUniqueDigits(123) == true);
    REQUIRE(AtUniqueDigits(132) == true);
    REQUIRE(AtUniqueDigits(321) == true);
    REQUIRE(AtUniqueDigits(113) == false);
    REQUIRE(AtUniqueDigits(223) == false);
    REQUIRE(true == true);
}

TEST_CASE("Compare IsUniqueDigits  DivMod vrs String ", "[023]") {
    std::array<int, 1000000> iterate;
    std::for_each(begin(iterate), end(iterate), [&](int i) {

        dsj::utils::TimeMetrics::Start("str");
        dsj::optimized::IsUniqueDigits(9876543210);
        dsj::utils::TimeMetrics::Stop("str");

        dsj::utils::TimeMetrics::Start("division");
        dsj::str::AtUniqueDigits(9876543210);
        dsj::utils::TimeMetrics::Stop("division");
    });
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("str") << std::endl;
    cout << "Total:" << dsj::utils::TimeMetrics::TotalTime("division") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("str") << std::endl;
    cout << "Ave:" << dsj::utils::TimeMetrics::Average("division") << std::endl;
}