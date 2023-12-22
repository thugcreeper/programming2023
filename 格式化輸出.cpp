#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[20];
    int year,month,day,money;
} peopleinfo;
int lengthofname(peopleinfo donate[],int time){
	int maxname=strlen(donate[0].name);
	for(int i=1;i<time;i++){
		if(strlen(donate[i].name)>maxname)
		maxname=strlen(donate[i].name);
	}
	return maxname;
}
int main(){
	int rptime;
	printf("Please input the number of donation records: ");
	scanf("%d",&rptime);
	peopleinfo donate[rptime];
	if (getchar() == '\r') getchar();
	printf("Please input the donor's name, donation date (year/month/day), and donation amount in one line.\n");
	
	for(int i=0;i<rptime;i++){
		char line[200];
		printf("Record %d: ",i+1);
		fgets(line,sizeof(line),stdin);
		sscanf(line, "%s %d/%d/%d %d", &donate[i].name, &donate[i].year, &donate[i].month, &donate[i].day, &donate[i].money);
		int var = scanf("%s %d/%d/%d %d", donate[i].name, &donate[i].year, &donate[i].month, &donate[i].day, &donate[i].money);//scanf 回傳讀到幾個變數 
		while(var != 5){
			printf("Incorrect format! Only got %d variable(s).\n",var);
			printf("Record %d: ",i+1);
			fgets(line,sizeof(line),stdin);
			var = scanf("%s %d/%d/%d %d", donate[i].name, &donate[i].year, &donate[i].month, &donate[i].day, &donate[i].money);
		}	
	}
	int maxname=lengthofname(donate,rptime);
	for(int i=0;i<rptime;i++){
		printf("%04d/%02d/%02d [%-*s] $%7d\n",donate[i].year,donate[i].month,donate[i].day,maxname,donate[i].name,donate[i].money);/s動態決定字串長度 
	}
	return 0;
}
