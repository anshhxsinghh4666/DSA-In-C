/*
Write an algorithm to change integer elements in an array such that 
    -> Each odd index element doubles of it 
    -> Every even index element halves if it 
*/

/*
Algorithm : 
-> Start 
-> Declare arrat arr and size n.
-> imitialize array arr
-> repeat st*/

#include <stdio.h>

int main() {
    int arr[10];
    int n = 10;

    for(int i=0; i<n; i++){
        printf("Enter Index %d : ", i);
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        if (i % 2 == 0) {
            arr[i] = arr[i] / 2; // Halve even index elements
        } else {
            arr[i] = arr[i] * 2; // Double odd index elements
        }
    }

    for(int i=0; i<n; i++){
        printf("Index %d : %d\n", i, arr[i]);
    }

    return 0;

}