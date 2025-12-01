// MERGE SORT :

/*
📌 ALGORITHM : Merge Function Only
Step 1: Set i = left, j = mid + 1, k = 0
  • i → pointer for left half
  • j → pointer for right half
  • temp[] → temporary array
Step 2: While i ≤ mid and j ≤ right, repeat:
  • If arr[i] ≤ arr[j], store arr[i] in temp[k], increment i and k
  • Else store arr[j] in temp[k], increment j and k
Step 3: Copy remaining elements of left half (if any)
Step 4: Copy remaining elements of right half (if any)
Step 5: Copy all elements from temp[] back to arr[left…right]
Step 6: End

ALGORITHM : Merge Sort
Step 1: If left < right, continue. Otherwise return (array of one element is already sorted)
Step 2: Find the midpoint
  • mid = (left + right) / 2
Step 3: Recursively call mergeSort(arr, left, mid)
  • This sorts the left half
Step 4: Recursively call mergeSort(arr, mid + 1, right)
  • This sorts the right half
Step 5: Call merge(arr, left, mid, right)
  • This merges the two sorted halves into one sorted segment
Step 6: End
*/

#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    // Merge in sorted order
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements of left half
    while (i <= mid) temp[k++] = arr[i++];

    // Copy remaining elements of right half
    while (j <= right) temp[k++] = arr[j++];

    // Copy sorted temp[] to original array
    k = 0;
    for (int p = left; p <= right; p++) arr[p] = temp[k++];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);  // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half
        merge(arr, left, mid, right);  // Merge halves
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\nOriginal Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
