#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getvalue(char c){
	if('0'<= c && c <= '9')
		return c-48;//change ascii code to actual number
	else if('A'<= c && c <= 'Z')//in hexadecimal A=10,ascii code of A =65
		return c-55;
	else if('a'<= c && c <= 'z')
		return c-87;
}
void check(char buffer[],int base){
	char *p = buffer;//p point to buffer[0]
	while(*p!='\0'){
		int k=getvalue(*p);
		if(k>= base){//if base =8,when read to 8 must stop
			*p ='\0';
		}
		p++;//don't forget to point to next address
	}
}
 int calc(char buffer[],int base){
	 int ans=0;
	
	for(int i=0;buffer[i]!='\0';i++){
		ans=ans*base+getvalue(buffer[i]);
	}
	return ans;
}
int main(){
	char ch, buffer[100];  int answer = 0, base, i;
	printf("請輸入進位制：");
	scanf("%d",&base); // get base from keyboard
	getchar(); // in order to get rid of the newline symbol '\n'
	printf("請輸入以該進位制表示的數：");
	fgets(buffer, sizeof(buffer), stdin);
	strtok(buffer, "\r\n");
	check(buffer,base);
	printf("輸入的數是 (%s",buffer);
	printf(")%d\n",base);
	answer= calc(buffer,base);
	printf("以十進位表示則為 %d",answer);
	return 0;
}
