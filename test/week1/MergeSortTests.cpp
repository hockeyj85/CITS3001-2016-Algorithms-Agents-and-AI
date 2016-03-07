//
// Created by james on 7/03/16.
//

#include "MergeSort.h"
#include "ArrayHelpers.h"
#include "gtest/gtest.h"

/**
 * Generate an array of size and run it aginst insertion sort and std::sort.
 * return false if they do not match.
 */
bool fuzzMergeSort(int size)
{
    int actual[size], expected[size];
    unsortedArray(actual, size);
    sortedArrayCopy(expected, actual, size);
    callMergeSort(actual, size);
    return arraysEqual(actual, expected, size);
}

TEST(Merge, CorrectStartingIndex)
{
    int a[] =  { 5, 6, 7, 8, 1, 2, 3, 4 };
    int aM[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    merge(a, 0, 3, 7);
    EXPECT_TRUE(arraysEqual(a, aM, 8));
}

TEST(Merge, MergesSubsection)
{
    int a[] =  { 5, 6, 7, 8, 1, 2, 3, 4 };
    int aM[] = { 5, 6, 1, 2, 7, 8, 3, 4 };
    merge(a, 2, 3, 5);
    EXPECT_TRUE(arraysEqual(a, aM, 8));
}

TEST(MergeSort, FuzzTest1000)
{
    EXPECT_TRUE(fuzzMergeSort(1000));
}

TEST(MergeSort, FuzzTest10000)
{
    EXPECT_TRUE(fuzzMergeSort(10000));
}

TEST(MergeSort, FuzzTest100000)
{
    EXPECT_TRUE(fuzzMergeSort(100000));
}

