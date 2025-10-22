// BINARY SEARCH : 


#include <stdio.h>

int main() {
    int n, i, key;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in **sorted order**: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Binary Search
    int low = 0, high = n - 1, mid;
    int found = 0; // flag to check if key is found

    while (low <= high) {
        mid = (low + high) / 2; // middle index

        if (arr[mid] == key) {
            found = 1;
            printf("Element %d found at position %d (0-indexed)\n", key, mid);
            break;
        } else if (arr[mid] < key) {
            low = mid + 1; // search in right half
        } else {
            high = mid - 1; // search in left half
        }
    }

    if (!found)
        printf("Element %d not found in the array.\n", key);

    return 0;
}