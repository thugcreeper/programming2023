#include<stdio.h>

int main(){
	int days,first_day,i,j = 0;
	printf("請問這個月有多少天？");
	scanf("%d",&days);
	printf("請問這個月第一天是星期幾？(0=星期天, 1=星期一, ...)");
	scanf("%d",&first_day);
	printf(" S  M  T  W  T  F  S\n");
	for( i =1;i<=days;i++){
		while(j < first_day){
			printf("   ");
			j++; 
		}
		printf("%2d ",i);
		if((first_day + i)%7 == 0)
		printf("\n");
	}
	return 0;
}

