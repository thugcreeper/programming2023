#include<stdio.h>
#include<string.h>
char * mystrtok(char str[], char brk[]){ 
	static char * nextp =NULL;
	char* token;
	if(str != NULL){
		nextp =str;
	}
	if(nextp != NULL){//step2
		while(*nextp != '\0' && strchr(brk,*nextp)!=NULL){
			nextp++;
		}
		if(*nextp == '\0')//nextp has pointed to the end of str, change its value into NULL.
		nextp = NULL;
	}
	if(nextp == NULL)//If now nextp is NULL, return NULL because there is no sentence to be separated.
		return NULL;
		
	token = nextp;//Set token as nextp.
	
	while(*nextp != '\0' && strchr(brk,*nextp)==NULL){//strchr(brk,*nextp)==NULL表示沒有找到要切的字元 
		nextp++;
	}
	if(*nextp == '\0')
		nextp = NULL;//nextp has pointed to the end of str, change its value into NULL
	else{
		*nextp='\0';
		nextp++;
	}	
	return token;
}

int main() {
    const int lineTotal = 4;
    char testline[lineTotal][100] = {
        "... Yes you got it!!! \\^^/",
        ".,?!///\\\\!!? ..",
        "",
        "A normal test. Hope it works!"
    };
    char brk[] = "., \\/?!";
    int i; char line[100], *token;
    for (i = 0; i < lineTotal; i++) {
        printf("Testing [%s] by strtok:\n", testline[i]);
        strcpy(line, testline[i]);
        token = strtok(line, brk);
        while (token != NULL) {
            printf("\t[%s]\n", token);
            token = strtok(NULL, brk);
        }
        printf("Testing [%s] by mystrtok:\n", testline[i]);
        strcpy(line, testline[i]);
        token = mystrtok(line, brk);
        while (token != NULL) {
            printf("\t[%s]\n", token);
            token = mystrtok(NULL, brk);
        }
    }
    return 0;
}
