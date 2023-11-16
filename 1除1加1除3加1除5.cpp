#include <stdio.h>

int main() {
    int data, i, num,j=0;
    double sum = 0.0;
    
    printf("How many sets of test data: ");
    scanf("%d", &data);

    while(j<data){
        printf("\n");
        printf("Input n (> 0): ");
        scanf("%d", &num);
		
        if (num <= 0) { 
            continue;
        }
		j++;

        if (num % 2 == 1) {
            printf("1/1 ");
            sum = 1.0; 
            for (i = 3; i <= num; i = i + 2) {
                printf("+ 1/%d ", i);
                sum += (1.0 / i); 
            }
        } 
		else { 
            printf("1/2 ");
            sum = 0.5; 
            for (i = 4; i <= num; i = i + 2) {
                printf("+ 1/%d ", i);
                sum += (1.0 / i); 
            }      
        }
        printf(" = %lf\n", sum);
    }

    return 0;
}
/*
Ask the user to input a positive integer n.
When n is an even number, output the sum of 1/2 + 1/4 + ... + 1/n.
When n is an odd number, output the sum of 1/1 + 1/3 + ... + 1/n.
If the input number is not positive, loop until we get one.
[Hint] Try 1.0/x instead of 1/x to get correct answers of divisions.*/
