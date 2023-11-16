#include<stdio.h>

int main(){
	int year,date,month,data;
	int month_date[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("幾組資料:");	scanf("%d",&data);
	for(int repeat =0;repeat<data;repeat++){
		printf("input date:");	scanf("%d/%d/%d",&year,&month,&date);
		if((year%4 == 0 && year%100 != 0) || year%400 == 0){
			month_date[1] = 29;
		}
			if(month < 13 && month >0){
			
				if(date > month_date[month -1] || date < 1){
					printf("%d/%d/%d is illegal\n",year,month,date);
	
				}
				else{
					printf("%d/%d/%d is legal\n",year,month,date);
				}
			}
			else{
				printf("%d/%d/%d is illegal\n",year,month,date);
	
				}
	}
	return 0;
} 
