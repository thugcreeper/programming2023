#include <stdio.h>

int main() {
    int data, m, n,p, element,sum=0;
    int a[20][20] = {0}, b[20][20] = {0}, c[20][20] = {0};

    printf("A is a matrix with m x n elements and\n");
    printf("B is a matrix with n x p elements.\n");
    printf("\n");
    printf("How many sets of test data: ");
    scanf("%d", &data);
    printf("\n");

    for (int repeat = 0; repeat < data; repeat++) {
        printf("Input values of m, n, p: ");
        scanf("%d %d %d", &m, &n,&p);

        printf("Input numbers in matrix A: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]); 
            }
        }

        printf("Input numbers in matrix B: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        printf("Numbers in matrix C are:\n");
		printf("{");
        for (int i = 0; i < m; i++) {
            printf("{");
            for (int j = 0; j < p; j++) {
            	c[i][j] = 0;
            	for(int k=0;k<n;k++){
            		c[i][j] += a[i][k] * b[k][j];
				}
                printf("%d", c[i][j]);
                
                if (j < p - 1) {
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

