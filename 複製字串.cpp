#include<stdio.h> 
#include<string.h> 
void duplicateStr(char dest[], char *src, int n) {
	dest[0] ='\0';
	for(int i=0;i<n;i++){
		strcat(dest,src);
	}
}

int main() {
    char newStr[500], inputStr[500];
    int ti, repeatTimes, rpTimes;
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes); // get repeatTimes from keyboard
    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a string: ");
        scanf("%s",&inputStr); // or fgets(???)
        printf("Duplicate how many times: ");
        scanf("%d",&rpTimes);
        duplicateStr(newStr, inputStr, rpTimes);
        printf("The new string is [%s]\n", newStr);
    }
    return 0;
}
