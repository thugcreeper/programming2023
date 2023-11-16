#include<stdio.h>

int main(){
	int amounta,amountb,total = 0;
	printf("Product A 購買數量：");
	scanf("%d",&amounta);
	printf("Product B 購買數量：");
	scanf("%d",&amountb);
	if(amounta <= amountb){
		total = amounta * 39 + 	((amountb - amounta)/2) * 32 + (amountb%2)*20 ;
		
	}
	if(amountb <= amounta){
		total = amountb * 39 + 	((amounta - amountb)/2) * 40 + (amounta%2)*25;
	}
	printf("總共是 %d 元。",total);
}
