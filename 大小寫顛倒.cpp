#include <stdio.h>
#include <string.h>

int main() {
    int repeatTimes, ti;
    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes);
    if (getchar() == '\r') getchar();//to skip '\r' and '\n' so that fgets(...) will not mistakenly get an empty line.

    char sent[300];
    for (ti = 0; ti < repeatTimes; ti++) {
        char *p = sent//point to sent[0];
        printf("\n");
        printf("Input a string: ");
        fgets(sent, sizeof(sent), stdin);
        strtok(sent, "\r\n");//使用 fgets(...) 讀進一行後，執行 strtok(...) 來刪除行尾的換行符號。
		printf("The new string [");
        while (*p != '\0') {
   
			if(*p>='A'&&*p<='Z'){
				*p += 32;
			}
			else if(*p>='a'&&*p<='z'){
            	*p -= 32;
			}
			printf("%c",*p);
            p++;
        }
        printf("]\n");
    }
    return 0;
}

