#include<stdio.h>
int fun1(int n);
int fun2(int n);
int main(){
	int data,limit;
	printf("How many sets of test data: ");		scanf("%d",&data);
	for(int i=0;i<data;i++){	
		printf("What is the upper limit? ");	scanf("%d",&limit);
		for(int n = 1;fun1(n)<=limit&&fun2(n)<=limit;n++){
			printf("n = %d, (a, b) = (%d, %d)\n",n,fun1(n),fun2(n));
		}
		printf("\n");
	}
}
int fun1(int n){
	if(n==1)    return 1;
	return fun1(n-1) + 2*fun2(n-1)+1;
}
int fun2(int n){
	if(n==1)    return 1;
	return 3*fun1(n-1) - fun2(n-1)+1;
}
