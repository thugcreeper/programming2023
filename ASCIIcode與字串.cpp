#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count_spaces(const char str[])
	{
	  int count = 0;
   const char * p = str;
	  while (*p != '\0') {
	    count++;
     p++;
   }
	  return count;
	}
int main(){
	char str[100];
	fgets(str, sizeof(str), stdin); strtok(str, "\r\n");//使用 fgets(...) 讀進一行後，執行 strtok(...) 來刪除行尾的換行符號。
	int count = count_spaces(str);
	for(int i=0;i<count;i++){
		printf("[%c] %d ==> [%c] %d\n",str[i],str[i],str[i]+1,str[i]+1);
	}
	return 0;
}
