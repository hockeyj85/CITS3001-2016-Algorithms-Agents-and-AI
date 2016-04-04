//
// Created by james on 7/03/16.
//

#include "ArrayHelpers.h"
#include <algorithm>

/**
 * Print the contents of an array
 */
void printArr(int A[], int s)
{
    for (int i = 0; i < s; i++) {
        std::cout << A[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 * Generate an unsorted array of size.
 */
void unsortedArray(int A[], int size)
{
    for (int i = 0; i < size; i++) {
        A[i] = rand();
    }
}

/**
 * Return a sorted copy of an array.
 */
void sortedArrayCopy(int dest[], int source[], int size)
{
    memcpy(dest, source, sizeof(int) * size);
    std::sort(dest, dest + size);
}

/**
 * Helper to asses array equality.
 */
bool arraysEqual(int A[], int B[], int size)
{
    for (int i = 0; i < size; i++) {
        if (A[i] != B[i]) {
            std::cout << A[i] << " " << B[i] << " " << i << std::endl;
            return false;
        }
    }
    return true;
}
