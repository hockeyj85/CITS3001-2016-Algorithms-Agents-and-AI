project(week1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        InsertionSort.cpp
        MergeSort.cpp InsertionSort.h MergeSort.h)

add_library(week1 ${SOURCE_FILES})
