#include<stdio.h>
int main() {

	int number,factor,count,i=0,flag=1;
    printf("Please input a positive number: ");		scanf("%d",&number); // get a positive number here
	printf("%d = ",number);
    for (factor = 2;factor <= number; factor++) { // two conditions: (1) final factor (2) number still needs to be factorized
        count =0; // reset to 0
        while (number%factor == 0) { // can be divided 
            number = number/ factor;// divide number by factor
			count++;
		
		
        } // this loop can be replaced with integer division directly
		
	
		if(count>0){
			if(flag == 0){
				printf("*");
			}
			printf("%d^%d",factor,count);
			flag = 0;
		}
        
        
    }
	
    return 0;
}
