include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../../src/week1)

add_executable(week1Tests
        InsertionSortTests.cpp
        MergeSortTests.cpp
        ArrayHelpers.cpp ArrayHelpers.h)

target_link_libraries(week1Tests week1)
target_link_libraries(week1Tests gtest gtest_main)