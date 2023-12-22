#include<stdio.h> 
#include<string.h>

int main() {
    char test[200] = "amsd，ams，owjej，elp[";
    char fuck[69] = "asd，a378q，oapokej，+as1z";
    char *p = strstr(test, "，");
    char *p2 = strstr(fuck, "，");
    printf("%s\n", test);
    printf("%s\n", fuck);
	printf("\n");
    while (p != NULL) {
        *p = ',';
        *(p + 1) = ' ';
        p = strstr(p + 1, "，");
    }

    while (p2 != NULL) {
        *p2=',';
        printf("%s\n",p2);//輸出p2指向的字串
        strncpy(p2 + 1, p2 + 2, strlen(p2 + 1));//strlen計算從 p2 + 1 開始的字串的長度
        p2 = strstr(p2 + 1, "，");
    }

    printf("\n%s\n", test);
    printf("%s", fuck);

    return 0;
}

