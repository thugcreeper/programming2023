#include<stdio.h>

int main(){
	int num,base,maxbase = 1,i=1;
	printf("請輸入一個非負整數：");		scanf("%d",&num);
	printf("請輸入進位制：");			scanf("%d",&base);
	
	while(i<=num){//num 10 base 2 1010 
		maxbase = i;
		i *= base;
	}
	printf("%d進位表示法：",base);
	while(maxbase>0){
		printf("%d",(num/maxbase)%base);
		maxbase /= base;
	}
	return 0;
}
