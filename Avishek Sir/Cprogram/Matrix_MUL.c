#include <stdio.h>

int main() {
    int m, n, p, q;

   
    printf("Enter number of rows and columns for matrix A (m x n): ");
    scanf("%d %d", &m, &n);

   
    printf("Enter number of rows and columns for matrix B (p x q): ");
    scanf("%d %d", &p, &q);

   
    if (n != p) {
        printf("Matrix multiplication not possible. The number of columns of A must be equal to the number of rows of B.\n");
        return 1;
    }

    
    int A[m][n], B[p][q], C[m][q];

   
    printf("Enter elements of matrix A (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    
    printf("Enter elements of matrix B (%d x %d):\n", p, q);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("B[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
        }
    }

   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    printf("\nResultant matrix C (%d x %d) after multiplication is:\n", m, q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
