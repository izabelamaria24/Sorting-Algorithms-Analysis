cmake_minimum_required(VERSION 3.26)
project(Sorting_Algorithms_Analysis)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Sorting_Algorithms_Analysis
        sortBenchmark.cpp
        sorts.hpp
        testgen.cpp)
