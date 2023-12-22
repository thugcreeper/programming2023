#include <stdio.h>
#include <string.h>

char *myStrRchr(char *sentence, char c) {
    if (sentence == NULL)
        return NULL;
	
    char *p = sentence + strlen(sentence) - 1;
    while (p >= sentence && *p != c) {
        p--;
    }
    if (*p == c)	return p;
        
    else	return NULL;      
}

int main() {
    char input;
    int ti, repeatTimes;
    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes);

    if (getchar() == '\r') getchar();

    for (ti = 0; ti < repeatTimes; ti++) {
        char arr[1000];
        printf("Input a string: ");
        fgets(arr, sizeof(arr), stdin);
        strtok(arr, "\r\n");

        printf("Divided by what symbol: ");
        scanf("%c", &input); 
        if (getchar() == '\r') getchar();

        char *p = arr;
        char *ans=myStrRchr(p, input);
		printf("Results:\n");
		printf("[%s]\n",p);
        while (ans != NULL) {
            *ans = '\0';
            printf("[%s]\n", p);
            ans=myStrRchr(p, input);
        }
	printf("\n");
    }
    return 0;
}
