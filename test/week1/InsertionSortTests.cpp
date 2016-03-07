//
// Created by james on 7/03/16.
//
#include "gtest/gtest.h"
#include "InsertionSort.h"
#include "ArrayHelpers.h"


/**
 * Generate an array of size and run it aginst insertion sort and std::sort.
 * return false if they do not match.
 */
bool fuzzInsertion(int size)
{
    int actual[size], expected[size];
    unsortedArray(actual, size);
    sortedArrayCopy(expected, actual, size);

    insertionSort(actual, size);
    return arraysEqual(actual, expected, size);
}

TEST(InsertionSort, FuzzTest1000)
{
    EXPECT_TRUE(fuzzInsertion(1000));
}

TEST(InsertionSort, FuzzTest10000)
{
    EXPECT_TRUE(fuzzInsertion(10000));
}

TEST(InsertionSort, FuzzTest100000)
{
    EXPECT_TRUE(fuzzInsertion(100000));
}

/* These are too slow

TEST(InsertionSort, FuzzTest1000000) {
    EXPECT_TRUE(fuzzInsertion(1000000));
}

TEST(InsertionSort, FuzzTest10000000) {
    EXPECT_TRUE(fuzzInsertion(10000000));
}

TEST(InsertionSort, FuzzTest100000000) {
    EXPECT_TRUE(fuzzInsertion(100000000));
}

TEST(InsertionSort, FuzzTest1000000000) {
    EXPECT_TRUE(fuzzInsertion(1000000000));
}
*/
