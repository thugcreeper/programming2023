#include <stdio.h>

int main() {
    int a, digits,i=0; 
    printf("How many sets of test data: ");
    int sets;
    scanf("%d", &sets);
	printf("\n");
    while(i<sets){
    	int x=0,s=0;
        printf("Input the value of a (1 ~ 9): ");
        scanf("%d", &a);
		if(a<1 || a>9){
			continue;
		}
		int validDigits = 0;
        while (validDigits == 0) {
            printf("Input the number of digits (1 ~ 9): ");
            scanf("%d", &digits);
            if (digits < 1 || digits > 9) {
                continue;
            } else {
                validDigits = 1;
            }
        }
        i++;
		printf("s = ");
        for (int j = 1; j <= digits; j++) {
            x = x * 10 + a;
            s += x;
			printf("%d", x);
			if (j < digits) {
                printf(" + ");
            }
            
   		}
		printf(" = %d\n", s);
		printf("\n");
        }
        
    return 0;
}
/*Find the value of s = a + aa + aaa + a...a
where the values of a and n are given by the user,
and the last term a...a has n digits.*/
