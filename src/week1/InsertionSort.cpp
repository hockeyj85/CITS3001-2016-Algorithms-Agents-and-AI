/**
 * In place insertion sort.
 *
 * @param A - The array to sort.
 * @param len - The length of the array.
 */
void insertionSort(int arr[], int len) {
	for(int i = 1; i < len; i++) {
		int j = i;
		int t = arr[i];
		while (j >= 1 && arr[j-1] > t) {
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = t;
	}
}

