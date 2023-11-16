#include <stdio.h>

int main() {
    int sets, sizes, i, j, time = 0;
    printf("How many sets of test data: ");
    scanf("%d", &sets);

    while (time < sets) {
        printf("Size: ");
        scanf("%d", &sizes);
        for (i = 0; i < sizes; i++) {
            for (j = 0; j < sizes; j++) {
            	if(i+j == sizes-4||i+j == sizes-3||i+j == sizes-2||i+j == sizes-1)
                printf("$");
                else
                printf("+");
            }
            printf("\n"); 
        }
        time++; 
        printf("\n");
    }
    return 0;
}






