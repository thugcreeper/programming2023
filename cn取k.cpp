#include<stdio.h>
int com(int n,int k){//combination
	if(k==0||k== n)		return 1;
	return com(n-1,k-1) + com(n-1,k);
}
int main(){
	for(int i=1;i<=6;i++){
		for(int j=0;j<=i;j++){
			printf("C(%d, %d) = %d\n",i,j,com(i,j));
		}
	}
	return 0;
}
