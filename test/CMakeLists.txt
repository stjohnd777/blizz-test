cmake_minimum_required(VERSION 3.17)
project(blizzard_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Question1Test ../question1/UniqueDigits.cpp utils/TimeMetric.hpp utils/TimeMetric.cpp catch.hpp TestUniqueDigits.cpp)

add_executable(Question2Test ../question2/DefinedSort.h utils/TimeMetric.hpp utils/TimeMetric.cpp catch.hpp TestDefinedSort.cpp)