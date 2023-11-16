#include<stdio.h>

int main(){
	int n,k,nextorder=1,count=0,i;
	int a[100]={0};
	printf("n = ");		scanf("%d",&n);
	printf("k = ");		scanf("%d",&k);
	for(i = 0;nextorder<=n;i++){
		for(i=0;i<n;i++){
			if(a[i] == 0)
				count++;
			if(count%k == 0 && a[i] == 0){
				a[i] = nextorder;
				nextorder++;
			}
		}
		i=0;
	}
	for(i = 0;i<n;i++){
		printf("The leaving order of person#%d is %d\n",i+1,a[i]);
	}
	return 0;
}
