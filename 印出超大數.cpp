#include<stdio.h> 
int main(){
	int data,interval;
    long long int num;
	printf("How many sets of test data: ");		scanf("%d",&data);
	for(int i=0;i<data;i++){
		printf("\nPlease input a large integer: ");		scanf("%lld",&num);
		printf("Please input an interval: ");			scanf("%d",&interval);
		printf("Your input is [%lld]\n",num);
		printf("Its next 10 numbers by adding %d are:\n",interval);
		for(int j=1;j<=10;j++){
			num+=interval;
			printf("%lld\n",num);//¦L¥Xlong long­n%lld 
		}
		printf("Over!!\n");
	}
	return 0;
}
