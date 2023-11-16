#include<stdio.h>

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int main() {
    int data, limit,a,b;
    printf("How many sets of test data: ");
    scanf("%d", &data);
    printf("\n");
	for(int i=0;i<data;i++){
		printf("a = ");		scanf("%d",&a);
		printf("b = ");		scanf("%d",&b);
		printf("GCD(%d, %d) = %d\n",a,b,gcd(a,b));
		printf("\n");
	} 

    return 0;
}

