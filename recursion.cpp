#include<stdio.h>

int recursionA(int n, int a, int b);
int recursionB(int n, int a, int b);

int main() {
    int data, limit, a, b;
    printf("How many sets of test data: ");
    scanf("%d", &data);
    printf("\n");

    for (int i = 0; i < data; i++) {
        printf("What is the upper limit? ");
        scanf("%d", &limit);

        for (int n = 1; recursionA(n, a, b) <= limit && recursionB(n, a, b) <= limit; n++) {
            a = recursionA(n, a, b);
            b = recursionB(n, a, b);
			printf("n = %d, (a, b) = (%d, %d)\n", n, a, b);
            
        }
        printf("\n");
    }

    return 0;
}

int recursionA(int n, int a, int b) {
    if (n == 1) {
        return 1;
    }
    return recursionA(n - 1, a, b) + 2 * recursionB(n - 1, a, b) + 1;
}

int recursionB(int n, int a, int b) {
    if (n == 1) {
        return 1;
    }
    return 3 * recursionA(n - 1, a, b) - recursionB(n - 1, a, b) + 1;
}



