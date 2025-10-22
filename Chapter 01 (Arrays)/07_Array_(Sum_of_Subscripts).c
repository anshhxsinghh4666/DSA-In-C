// Initialize a 2-D array with sum of their subscript

/*
Algorithm :
-> Start
-> Declare row and col
-> Take input row and col from user 
-> Delcare 2-D array as arr[row][col]
-> repeat step 6 for row = 0 to row-1
-> repeat step 7 for col = 0 to col-1
-> arr[row][col] = row + col;
-> End 
*/


#include <stdio.h>
int main(){
    int arr[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j] = i + j;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=i+j;
        }
    }

    return 0;
}