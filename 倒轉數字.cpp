#include<stdio.h> 
int main(){
	int data,i,num;
	printf("How many sets of test data: ");			scanf("%d",&data);
	for(i=0;i<data;i++){
		printf("\n");
		printf("Input a number: ");				scanf("%d",&num);
		printf("Reverse: ");
		while(num!=0){
			printf("%d",num%10);
			num /= 10;
		}
		printf("\n");
	}
	return 0;
	}
/*
Reverse a number.
ex input 12345-> 54321*/
