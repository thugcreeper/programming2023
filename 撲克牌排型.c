#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char* suitSymbol[4] = {"♣", "♦", "♥", "♠"};
char* highRank[4] = {"J", "Q", "K", "A"};

int checkFlush(int suitCount[]) {//check是否同花色
    for (int i = 0; i < 4; i++) {
        if (suitCount[i] == 5) {
            return 1; // is flush
        }
    }
    return 0; // not a flush
}

int checkStraight(int rankCount[]) {//check是否是順子
    int accum[14];

    for (int i = 0; i < 14; i++) {
        if (i == 13 && rankCount[i] > 0) {
            accum[i] = 1;
        }
        if (rankCount[i] == 0) {
            accum[i] = 0;
        }
        if (rankCount[i] > 0) {
            accum[i] = accum[i + 1] + 1;
        }
        if (accum[i] == 5) {
            return 1; // is straight
        }
    }

    return 0; // not a straight
}

int handRanking(int hand[]) {
    int suitCount[4] = {};//統計花色
    int rankCount[14] = {};
    int countSlot[5] = {};// countSlot用來統計rankCount中的每個值的個數

    for (int i = 0; i < 5; i++) {
        int suit = hand[i] / 13;
        int rank = hand[i] % 13;
        suitCount[suit]++;
        rankCount[rank]++;
    }

    int isFlush = checkFlush(suitCount);
    int isStraight = checkStraight(rankCount);

    for (int i = 0; i < 14; i++) {
        countSlot[rankCount[i]]++;
    }

    if (isFlush && isStraight) {
        return 8; // 同花順
    } else if (isFlush) {
        return 5; // 同花
    } else if (isStraight) {
        return 4; // 順
    } else if (countSlot[4] == 1) {
        return 7; // 四條
    } else if (countSlot[3] == 1 && countSlot[2] == 1) {
        return 6; // 葫蘆
    } else if (countSlot[3] == 1) {
        return 3; // 三條
    } else if (countSlot[2] == 2) {
        return 2; // 二對
    } else if (countSlot[2] == 1) {
        return 1; // 一對
    } else {
        return 0; // 無
    }
}

void shuffling(int a[], int N) {//洗牌排從0-N
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

void printCard(int id) {
    printf("%s", suitSymbol[id / 13]);
    if (id % 13 <= 8)
        printf("%d ", id % 13 + 2);
    else
        printf("%s ", highRank[id % 13 - 9]);
}

void printtype(int rank){
    switch (rank) {
        case 8:
            printf("同花順\n");
            break;
        case 7:
            printf("四條\n");
            break;
        case 6:
            printf("葫蘆\n");
            break;
        case 5:
            printf("同花\n");
            break;
        case 4:
            printf("順\n");
            break;
        case 3:
            printf("三條\n");
            break;
        case 2:
            printf("兩對\n");
            break;
        case 1:
            printf("一對\n");
            break;
        default:
            printf("無\n");
        }

}
int main() {
    int a[52] = {};
    int hand[5]; // Array to store input cards

    srand((unsigned)time(NULL));
    system("chcp 65001");

    for (int i = 0; i < 10; i++) {
        shuffling(a, 52);
        for (int k = 0; k < 5; k++) {
            printCard(a[k]);
        }
    int rank = handRanking(a);

        // Print hand ranking
        printtype(rank);
    }

    while (1) {
        printf("Input cards: ");

        for (int i = 0; i < 5; i++) {
            scanf("%d", &hand[i]);
            if (hand[i] == -1)
                break;
            printCard(hand[i]);
        }

        // Check hand ranking
        int rank = handRanking(hand);

        // Print hand ranking
        printtype(rank);
    }
    return 0;
}
