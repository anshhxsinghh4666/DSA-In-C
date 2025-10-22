// SORTING OF 1D ARRAY :

#include <stdio.h>

void display(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int n, int arr[n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array After Bubble Sort : \n");
    display(n, arr);
}

void selectionSort(int n, int arr[n]) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
    printf("Array after Selection Sort : \n");
    display(n, arr);
}

void insertionSort(int n, int arr[n]) {
    int i, key, j;
    for (i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Array after Insertion Sort : \n");
    display(n, arr);
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter nments of Array : \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(n, arr);

    selectionSort(n, arr);

    insertionSort(n, arr);

    return 0;
}