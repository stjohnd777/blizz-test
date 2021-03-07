cmake_minimum_required(VERSION 3.17)
project(blizzard)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

add_executable(blizzard UniqueDigits.h UniqueDigits.cpp DefinedSort.h ./test/TimeMetric.cpp  main.cpp)


