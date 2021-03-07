cmake_minimum_required(VERSION 3.17)
project(blizzard_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Question1Test ../UniqueDigits.cpp TimeMetric.hpp TimeMetric.cpp catch.hpp TestUniqueDigits.cpp)

add_executable(Question2Test ../DefinedSort.h TimeMetric.hpp TimeMetric.cpp catch.hpp TestDefinedSort.cpp)