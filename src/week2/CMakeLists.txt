cmake_minimum_required(VERSION 3.3)

project(week2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Boyer-Moore.cpp
        Boyer-Moore.h
        Knuth-Morris-Pratt.cpp
        Knuth-Morris-Pratt.h
        LCS.cpp
        LCS.h
        NaiveStringMatcher.cpp
        NaiveStringMatcher.h
        Rabin-Karp.cpp
        Rabin-Karp.h)

add_library(week2 ${SOURCE_FILES})