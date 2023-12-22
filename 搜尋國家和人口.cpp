#include<stdio.h> 
#include<string.h> 
#define countryTotal 21

int indexOfList(char str[], char *list[], int itemTotal){//最後是傳21 
	for(int i=0;i<countryTotal;i++){
		if(strcmp(str,list[i])==0){
			return i;
			break;
		}
		
	}
		return -1;
}
	char *country[countryTotal] = {
			"China",
			"Japan",
			"Korea",
			"India",
			"Indonesia",
			"Malaysia",
			"Singapore",
			"Thailand",
			"Viet Nam",
			"Taiwan",
			"Mexico",
			"Brazil",
			"Canada",
			"USA",
			"the United Kingdom",
			"Italy",
			"Spain",
			"France",
			"Germany",
			"Australia",
			"New Zealand"
		};
	
	int population[countryTotal] = {
		1425887, 123952, 51816, 1417173, 275501,
		33938, 5976, 71697, 98187, 23893, 127504,
		215313, 38454, 338290, 67509, 59037, 47559,
		64627, 83370, 26177, 5185
	};
int main(){
	
	printf("Welcome to the World Population Database!\n");
	
	while(1){
		char input[100]={};
		
		printf("\nInput a country (\"quit\" to exit): ");
		fgets(input,sizeof(input),stdin);
		strtok(input,"\r\n");
		int index=indexOfList(input, country,countryTotal);
		if(index>0){
			printf("\nThe population of the %s is %d thousands.\n",country[index],population[index]);
		}
		if(index<0){
			if(strcmp(input,"quit")==0)
				break;
		
			else
				printf("Sorry, we cannot find [%s] in our database.\n",input);
			}
	}
	printf("\nThank you for using World Population Database!");
	return 0;
}
