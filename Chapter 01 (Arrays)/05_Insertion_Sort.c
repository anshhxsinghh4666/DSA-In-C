// INSERTION SORT :

/*
ALGORITHM : Insertion Sort Section Only
Step 1: Loop from i = 1 to i = n − 1. Repeat the following steps:
  • Set key = arr[i]
  • Set j = i − 1
  • While j ≥ 0 and arr[j] > key, repeat:
    - Set arr[j + 1] = arr[j]
    - Decrease j by 1
  • After the loop ends, set arr[j + 1] = key
Step 2: End
*/

// TC = O(n^2)

#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];  // Current element to be inserted
        j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Place the key at its correct position
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}