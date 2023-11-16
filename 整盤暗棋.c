#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[4][8] = {0};
char *chessname[2][9] = {{"卒", "", "", "包", "馬", "車", "象", "士", "將"}, {"兵", "", "", "炮", "傌", "俥", "相", "仕", "帥"}};

// Function declaration
void shuffling(int a[], int n);

int rank(int id) {
    if (id > 16)
        id -= 16;
    int k = id / 2; // rank
    if (k < 3)
        k = 0;
    return k;
}

int color(int id) {
    if (id <= 16)
        return 0; // black chess
    else
        return 1; // red chess
}

void gameInit() {
    shuffling(board, 32); // shuffle the chessintpieces on the board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] *= -1; // flip the pieces face down
        }
    }
}

void shuffling(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    int t;
    for (int k = 0; k < n; k++) {
        int c = rand() % n;
        int d = rand() % n;
        t = a[c];
        a[c] = a[d];
        a[d] = t;
    }
}

void printBoard() {
    for (int i = 0; i < 4; i++) {
        if (i == 0)
            printf("┌───┬───┬───┬───┬───┬───┬───┬───┐\n");
        else
            printf("├───┼───┼───┼───┼───┼───┼───┼───┤\n");
        for (int j = 0; j < 8; j++) {
            if (board[i][j] < 0)
                printf("│●　");
            else if (board[i][j] == 0)
                printf("│　 ");
            else
                printf("│%s ", chessname[color(board[i][j])][rank(board[i][j])]);
        }
        printf("│\n");
    }
    printf("└───┴───┴───┴───┴───┴───┴───┴───┘\n");
}

int main() {
    int movingX[4] = {-1, 1, 0, 0};
    int movingY[4] = {0, 0, -1, 1};
    int num1, num2, move;
    srand((unsigned int)time(NULL));
    system("chcp 65001 & cls"); // (for Windows users) force the command window to show unicode characters
    gameInit();
    //printBoard();
    while (1) {
        printBoard();
        printf("\nNow it's turn for Player 1.\n");
        printf("Choose a cell (-1 for exit): ");
        scanf("%d %d", &num1, &num2);

        if (num1 == -1) {
            printf("Thank you!! Bye~~");
            break;
        }
        else if(board[num1][num2] == 0)
            continue;
        else if(board[num1][num2]<0)
            board[num1][num2] *= -1;
        else{
            printf("Move to which direction (0, 1, 2, 3 for up, down, left, and right): ");
            scanf("%d",&move);
            int x,y;
            x = num1+ movingX[move];
            y = num2+ movingY[move];
            if(x<0 || y<0 || x>3 ||y>7){
                    continue;

            }
            board[x][y] = board[num1][num2];
            board[num1][num2] = 0;
        }

    }
    return 0;
}


