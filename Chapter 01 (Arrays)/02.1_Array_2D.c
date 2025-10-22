// TWO DIMENSIONAL ARRAY :

#include <stdio.h>

void addition(int r, int c, int arr[r][c], int arr_[r][c]) {
    int sum[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = arr[i][j] + arr_[i][j];
        }
    }
    printf("Sum of Matrix 1 And Matrix 2 : \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf(" %d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(int r, int c, int arr[r][c]) {  // Works for Both Square and Rectangle Matrix
    int tran[c][r];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tran[j][i] = arr[i][j];
        }
    }
    printf("Transpose of Matrix : \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf(" %d ", tran[i][j]);
        }
        printf("\n");
    }
}

void multiply(int r, int c, int arr1[r][c], int arr2[r][c]) {
    int result[r][c];
    // Matrix multiplication is only valid if columns of arr1 == rows of arr2
    // Here, both matrices are r x c, so multiplication is only valid for square matrices
    // For general case, you should take dimensions accordingly

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Multiplication of Matrix 1 and Matrix 2 :\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf(" %d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int r, c;
    printf("Enter Number of Rows : ");
    scanf("%d", &r);
    printf("Enter Number of Columns : ");
    scanf("%d", &c);

    int a[r][c], b[r][c];

    printf("Enter Values of Matrix 1 : \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("R%d C%d : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Values of Matrix 2 : \n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("R%d C%d : ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    int ch;

    do {
        printf(
            "Enter Choice : \n 1. Addition \n 2. Transpose of Matrix 1 \n 3. Transpose of Matrix 2 \n 0. Exit.... \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                addition(r, c, a, b);
                break;
            case 2:
                transpose(r, c, a);
                break;
            case 3:
                transpose(r, c, b);
                break;
            case 0:
                printf("Exiting....\n");
                break;
            default:
                printf("Invalid Input \n");
                break;
        }
    } while (ch != 0);

    return 0;
}
