cmake_minimum_required(VERSION 3.17)
project(blizzard_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Question1Test ../UniqueDigitsQuestion.cpp  TimeMetric.hpp TimeMetric.cpp catch.hpp UniqueDigitsTest.cpp)

