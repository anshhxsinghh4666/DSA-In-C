// BINARY SEARCH :

/*
ALGORITHM : Binary Search Section Only
Step 1: Set low = 0, high = n − 1, found = 0
Step 2: Repeat while low ≤ high:
  • Set mid = (low + high) / 2
  • If arr[mid] == key:
    - Set found = 1
    - Print position
    - Break the loop
  • Else if arr[mid] < key:
    - Set low = mid + 1
  • Else:
    - Set high = mid − 1
Step 3: If found == 0, print that the element is not found
Step 4: End
*/

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
    int found = 0;  // flag to check if key is found

    while (low <= high) {
        mid = (low + high) / 2;  // middle index

        if (arr[mid] == key) {
            found = 1;
            printf("Element %d found at position %d (0-indexed)\n", key, mid);
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;  // search in right half
        } else {
            high = mid - 1;  // search in left half
        }
    }

    if (!found)
        printf("Element %d not found in the array.\n", key);

    return 0;
}