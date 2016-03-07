#include "MergeSort.h"
#include <climits>

/**
 * Merge two contiguous sorted sections of an array in to a combined sorted section.
 * @param A - the array to use.
 * @param p - the index of the first element of the left section.
 * @param q - the index of the last element of the left section.
 * @param r - the index of the last element of the right section.
 */
void merge(int A[], int p, int q, int r)
{
    // define two temp arrays
    int n1 = q - p + 1;
    int n2 = r - q; // already has an extra element from q.
    int L[n1 + 1], R[n2 + 1];

    // Fill them with a copy of what was in A
    memcpy(L, &A[p], sizeof(A[0]) * n1);
    memcpy(R, &A[q+1], sizeof(A[0]) * n2);
    memset(&A[p], '\0', sizeof(A[0]) * (r - p - 1)); // Set mem in A to 0 for debug.

    // Make last element big!
    int big = INT_MAX;
    L[n1] = big;
    R[n2] = big;

    // Merge them back into A.
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void callMergeSort(int A[], int size) {
    mergeSort(A, 0, size - 1);
}

/**
 * Mergesort an array.
 *
 * @param A - the array to sort
 * @param l - the index of the leftmost element in the array.
 * @param r - the index of the rightmost element in the array.
 */
void mergeSort(int A[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	mergeSort(A, l, m);
	mergeSort(A, m+1, r);
	merge(A, l, m, r);
}

