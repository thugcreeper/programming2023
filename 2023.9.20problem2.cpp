#include<stdio.h>

int main(){
	int input_num;
	printf("Please input a positive number: ");
	scanf("%d",&input_num);
	for(int i = 1;i <= input_num;i++){
		printf("%d / %d = %lf\n",i,i+1,(i*1.0)/(i+1));
	}
	
	return 0;
}

