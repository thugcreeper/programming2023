#include<stdio.h>

int main(){
	int  beginningDay[12]={20,20,21,21,21,22,23,23,23,23,22,22};
	char * zodiacName[12] = {"牡羊座", "金牛座","雙子座","巨蟹座","獅子座","處女座","天秤座","天蠍座","射手座","摩羯座","水瓶座","雙魚座"};
	int mon,date,zodiacCode;
	printf("請輸入日期 (以 月/日 的格式)：");	scanf("%d/%d",&mon,&date);
	zodiacCode = (mon + 9) % 12;
	if (date < beginningDay[ mon-1 ] ){
		zodiacCode = (zodiacCode -1 + 12) % 12;
	}
	printf("你是%s的，星座代碼是 %d。", zodiacName[ zodiacCode ],zodiacCode);
	return 0;
}
