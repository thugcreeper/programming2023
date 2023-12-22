#include<stdio.h>
#include<string.h>

int main(){
	int rptime,count;
	char line[500],token[100],*p;
    printf("How many sets of test data: ");
    scanf("%d", &rptime);if (getchar() == '\r') getchar();
    for (int i = 0; i < rptime; i++) {
    	count=0;
        printf("\nInput a string: ");
        fgets(line,sizeof(line),stdin);
        strtok(line,"\r\n");
        printf("Divided by what symbols: ");
        fgets(token,sizeof(token),stdin);
        strtok(token,"\r\n");
        p=strtok(line,token); 
        while(p!=NULL){
       		count++;
       		printf("[%s] length = %d\n",p,strlen(p));	
       		p=strtok(NULL,token);
	   }
    }
	return 0;
}
