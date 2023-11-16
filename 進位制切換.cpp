#include<stdio.h> 
int main(){
	int data,interval,base;
    int num;
	printf("How many sets of test data: ");		scanf("%d",&data);
	for(int i=0;i<data;i++){
		printf("\nInput in what base (1) decimal (2) octal (3) hexadecimal: ");	
		scanf("%d",&base);
		printf("Input a number: ");	
		if(base == 1)
		scanf("%d",&num);
		
		else if(base==2)
		scanf("%o",&num);
		
		else if(base==3)
		scanf("%x",&num);
		
		printf("This number is\n");
		printf("%d in decimal\n",num);
		printf("%o in octal, and\n",num);
		printf("%x in hexadecimal.\n",num);
	}
	return 0;
}
