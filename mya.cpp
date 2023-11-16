#include<stdio.h>
int mya(int k,int m,int n,int s,int t){
	if(k == 0)  return 0;
	if(k%2==1)  return m*mya(k-1,m,n,s,t) + n;
	if(k%2==0)  return s*mya(k-1,m,n,s,t) + t;
}


int main() {
    int data, limit,m,n,s,t,index;
    printf("How many sets of test data: ");
    scanf("%d", &data);
    printf("\n");

    for (int i = 0; i < data; i++) {
		printf("m = ");		scanf("%d",&m);
        printf("n = ");		scanf("%d",&n);
        printf("s = ");		scanf("%d",&s);
        printf("t = ");		scanf("%d",&t);
        printf("Final index = ");		scanf("%d",&index);
    	for(int j=0;j<=index;j++){	
        printf("a_%d = %d\n",j,mya(j,m,n,s,t));
		}
		printf("\n");
        
    }

    return 0;
}


