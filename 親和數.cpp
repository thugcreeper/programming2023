#include<stdio.h>

int main(){
	int a[10000] ={};
	int sum=0,k=0,i,j;
	for(i=1;i<10000;i++){
		for(sum=0,j=1;j<i;j++){
			if(i%j==0){//if j is i's计 
				sum += j;//i's计㎝ 
			}		
		}
		a[i]=sum;
	}
	for(int i=1;i<10000;i++){
		for(int j=i+1;j<10000;j++){
			if(a[i]==j && a[j] ==i)//i's计㎝=jj's计㎝=i ->克㎝计 
			printf("%d %d\n",a[i],a[j]);
		}
	}
	return 0;
}
