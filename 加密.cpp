#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void change(char str[]){
	char *p=str;
	while(*p!='\0'){//if char != end,do loop
		if(*p>='a'&&*p<='z')
			*p = (*p-'a'+2)%26+'a';
		else if(*p>='A'&&*p<='Z')
			*p = (*p-'A'+2)%26+'A';
		else if(*p>='0'&&*p<='9')
			*p = (*p - '0' + 9) % 10 + '0';//*p - '0' Convert characters to corresponding numbers +9%10 let0=9 1=0 9=8 + '0' make them become char
		p++;
	}
}
int main(){
	for(int i=0;i<4;i++){
		char str[500];
		printf("Input a line  : ");
		fgets(str,sizeof(str),stdin);
		strtok(str,"\r\n");
		change(str);
		printf("\nEncrypted line: %s\n",str);
	}
	return 0;
}
