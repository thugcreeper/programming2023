#include<stdio.h>//¥Îcodeblock¤~¥i¥H°õ¦æ 
#include<stdlib.h>
#include<time.h>
void shuffling(int a[], int N) {        //Næ˜¯æœ‰å¹¾å¼µç‰Œ
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    for (int k = 0; k < N; k++) {
        int i = rand() % N;
        int j = rand() % N;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
void printCard(int id){
	char* suitSymbol[4] = {"â™£", "â™¦", "â™¥", "â™ "};
	char* highRank[4] = {"J", "Q", "K", "A"};
	printf("%s",suitSymbol[id/13]);
        if(id%(13)<=8)
            printf("%d ",id%13+2);
        else
            printf("%s ",highRank[id%13-9]);

}

int main() {
    int a[52]={};
    srand( (unsigned)time(NULL) );
    system("chcp 65001");
    int id = 0;
    shuffling(a, 52);
    int k = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 13; j++) {
            printCard(a[k]);
            k++;
        }
        printf("\n");
    }

    while (1) {
        printf("Input a card ID: ");
        scanf("%d", &id); if (id == -1) break;
        printCard(id);
        putchar('\n');
    }
    return 0;
}

