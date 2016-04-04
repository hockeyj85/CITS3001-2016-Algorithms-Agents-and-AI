cmake_minimum_required(VERSION 3.3)

project(week3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Knapsack.cpp Knapsack.h FractionalKnapsack.cpp FractionalKnapsack.h)

add_library(week3 ${SOURCE_FILES})
