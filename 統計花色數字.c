#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char* suitSymbol[4] = {"♣", "♦", "♥", "♠"};
char* highRank[4] = {"J", "Q", "K", "A"};

void suitCounting(int cards[], int suitCount[]) {//統計花色
    for (int i = 0; i < 4; i++) {
        suitCount[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
        int suit = cards[i] / 13;
        suitCount[suit]++;
    }
}

void rankCounting(int cards[], int rankCount[]) {//統計數字
    for (int i = 0; i < 14; i++) {
        rankCount[i] = 0;
    }
    for (int i = 0; i < 5; i++) {
        int rank = cards[i] % 13;
        rankCount[rank]++;
    }
}

void printCard(int id) {
    printf("%s", suitSymbol[id / 13]);
    if (id % 13 <= 8)
        printf("%d ", id % 13 + 2);
    else
        printf("%s ", highRank[id % 13 - 9]);
}

int main() {

    int a[52] = {};
    int suitCount[4] = {};
    int rankCount[14] = {};
    int cards[5];  // Array to store input cards
    srand((unsigned)time(NULL));
    system("chcp 65001");

    while (1) {

        printf("Input cards: ");

        for (int i = 0; i < 5; i++) {
            scanf("%d", &cards[i]);
            if (cards[i] == -1) break;
            printCard(cards[i]);
        }

        printf(" have\n");

        suitCounting(cards, suitCount);
        rankCounting(cards, rankCount);

        for (int m = 0; m < 4; m++) {
            printf("%s(%d) ", suitSymbol[m], suitCount[m]);     //print花色和數字
        }
        printf("\n");

        for (int n = 2; n <= 10; n++) {                         //print2-10
            printf("%d(%d) ", n, rankCount[n-2]);
        }
        for (int n = 0; n <= 3; n++) {                          //print JQKA
            printf("%s(%d) ", highRank[n], rankCount[n+9]);
        }
        printf("\n");
    }

    return 0;
}



