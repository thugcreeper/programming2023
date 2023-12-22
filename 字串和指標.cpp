#include<stdio.h> 
#include<string.h> 
int main(){
	int data,skip;
	printf("How many sets of test data: ");
	scanf("%d",&data); if (getchar() == '\r') getchar();
	for(int i=0;i<data;i++){
		char str[500]={};
		printf("\nInput a string: ");
		fgets(str,sizeof(str),stdin);
		strtok(str,"\r\n");
		printf("Skipping = ");
		scanf("%d",&skip); if (getchar() == '\r') getchar();
		char *strEndp=str;
		char *p=str;
		while(*strEndp!='\0'){
			strEndp++;
		}
		strEndp--;
		while(p<=strEndp){//不斷印出字串直到超出最後的指標 
			printf("[%s]\n",p);//指標p指向p，會直接印出p陣列 
			p+=skip;
		}
		
	}
	return 0;
}
