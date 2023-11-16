#include<stdio.h>

int main(){
	int firstprize,inputnum;
	printf("請輸入頭獎號碼：");
	scanf("%d",&firstprize);
	
	if(firstprize > 99999999)
	printf("error");
	printf("請輸入你的發票號碼：");
	scanf("%d",&inputnum);
	if(inputnum == firstprize){
		printf("恭喜！你中了頭獎！");
	}
	else if (inputnum % 10000000 == firstprize % 10000000){
		printf("恭喜！你中了二獎！");
	}
	else if (inputnum % 1000000 == firstprize % 1000000){
		printf("恭喜！你中了三獎！");
	}
	else if (inputnum % 100000 == firstprize % 100000){
		printf("恭喜！你中了四獎！");
	}
	else if (inputnum % 10000 == firstprize % 10000){
		printf("恭喜！你中了五獎！");
	}
	else if (inputnum % 1000 == firstprize % 1000){
		printf("恭喜！你中了五獎！"); 
	} 
	else{
		printf("抱歉沒有中獎。");
	}
	return 0;
}

