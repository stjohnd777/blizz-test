cmake_minimum_required(VERSION 3.17)
project(blizzard)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

add_executable(blizzard question1/UniqueDigits.h question1/UniqueDigits.cpp question2/DefinedSort.h test/utils/TimeMetric.cpp main.cpp)


