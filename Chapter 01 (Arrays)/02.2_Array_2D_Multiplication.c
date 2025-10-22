// WAP to find multiplication of two matrices A and B . Take matrice A and B from the user.

#include <stdio.h>

int main() {
    int r1, r2, c1, c2;
    printf("Matrix 1 : \n");
    printf("Enter Number of Rows : ");
    scanf("%d", &r1);
    printf("Enter Number of Columns : ");
    scanf("%d", &c1);
    printf("\n");
    printf("Matrix 2 : \n");
    printf("Enter Number of Rows : ");
    scanf("%d", &r2);
    printf("Enter Number of Columns : ");
    scanf("%d", &c2);

    // Matrix multiplication is possible only if c1 == r2
    if (c1 != r2) {
        printf("NOT POSSIBLE !! Number of columns of Matrix 1 must be equal to number of rows of Matrix 2\n");
        return 0;
    }

    int a[r1][c1], b[r2][c2], r[r1][c2];

    printf("Enter Elements of Matrix 1 : \n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("(%d , %d) : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Elements of Matrix 2 : \n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("(%d , %d) : ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            r[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplication of Matrix A and B :\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }

    return 0;
}