#include <stdio.h>

int main() {
    int data, m, n, element;
    int a[20][20] = {0}, b[20][20] = {0}, c[20][20] = {0};

    printf("Both A and B are matrices with m x n elements.\n");
    printf("\n");
    printf("How many sets of test data: ");
    scanf("%d", &data);
    printf("\n");

    for (int repeat = 0; repeat < data; repeat++) {
        printf("Input values of m and n: ");
        scanf("%d %d", &m, &n);

        printf("Input numbers in matrix A: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
                //a[i][j] = element; 
            }
        }

        printf("Input numbers in matrix B: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &b[i][j]);
                //b[i][j] = element;
            }
        }

        printf("Numbers in matrix C are:\n");
		printf("{");
        for (int i = 0; i < m; i++) {
            printf("{");
            for (int j = 0; j < n; j++) {
                c[i][j] = a[i][j] + b[i][j];
                printf("%d", c[i][j]);
                if (j < n - 1) {
                    printf(", ");
                }
            }
            printf("}");
            if (i < m - 1) {
                printf(",\n");
            }
            
        }
        printf("}\n");
        printf("\n");
    }

    return 0;
}

