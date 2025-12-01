// Bubble Sorting Of Arrays.

/*
ALGORITHM : Bubble Sort of an Array
Start
Declare integer variable :
    ~ n (number of elements)
Input value of n from user
Declare an integer array of size n :
    ~ arr[n]
Print message “Enter Elements of Array : ”
Loop from i = 0 to i = n - 1, repeat the following:
    ~ Input value into arr[i]
Print “Original array:”
Loop from i = 0 to i = n - 1, repeat the following:
    ~ Print arr[i]
Bubble Sort Logic (Nested Loops):
    ~ Loop from i = 0 to i = n - 1
    • Loop from j = 0 to j = n - i - 2
        → Check if arr[j] > arr[j+1]
        → If TRUE, then swap arr[j] and arr[j+1] using a temporary variable temp
Print “Sorted array:”
Loop from i = 0 to i = n - 1, repeat the following:
    ~ Print arr[i]
Print newline
End


ALGORITHM : Bubble Sort Section Only
Loop from i = 0 to i = n − 2, repeat the following steps :
~ Loop from j = 0 to j = n − i − 2, repeat the following :
  → Check if arr[j] > arr[j + 1]
  → If TRUE :
   • Store arr[j] in temp
   • Set arr[j] = arr[j + 1]
   • Set arr[j + 1] = temp
End

*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter Elements of Array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble Sort logic directly in main
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}