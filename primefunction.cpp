#include <stdio.h>

int isPrime(int num) {
    for (int divisor = 2; divisor * divisor <= num; divisor++) {
        if (num % divisor == 0)
            return 0;
    }
    return 1;
}

int main() {
    int repeatTimes, num, k;

    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes);

    for (int ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a number (>= 6): ");
        scanf("%d", &num);

        for (int i = 2; i < num; i++) {
            for (int j = 2; j < num; j++) {
                k = num - i - j;

                if (isPrime(i) && isPrime(j) && isPrime(k) && (i <= j && j <= k)) {
                    printf("%d = %d + %d + %d\n", num, i, j, k);
                }
            }
        }
    }

    return 0;
}


