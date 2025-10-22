// Given a sorted array of integer values, analyze the problem of finding two distinct
// values in the array whose sum is 90. Write a C program (not the algorithm) to solve
// this problem. The function should be named findsum(int arr[], int n).


#include <stdio.h>

void findsum(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == 90) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return;
        } else if (sum < 90) {
            left++;
        } else {
            right--;
        }
    }
    printf("No pair found with sum 90\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};  // Sorted Array
    int n = sizeof(arr) / sizeof(arr[0]);
    findsum(arr, n);
    return 0;
}
