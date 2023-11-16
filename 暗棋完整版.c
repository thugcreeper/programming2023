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
    shuffling(board, 32); // shuffle the chess pieces on the board
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
    int num1, num2, move, playerid = 1;
    srand((unsigned int)time(NULL));
    system("chcp 65001 & cls"); // (for Windows users) force the command window to show unicode characters
    gameInit();

    while (1) {
        printBoard();
        printf("\nNow it's turn for Player %d.\n", playerid);
        printf("Choose a cell (-1 for exit): ");
        scanf("%d %d", &num1, &num2);

        if (num1 == -1) {
            printf("Thank you!! Bye~~");
            break;
        }
        else if (board[num1][num2] == 0) {//no chess
            continue;
        }
        else if (board[num1][num2] < 0) {//蓋起來的棋子
            board[num1][num2] *= -1;
        }
        else if(color(board[num1][num2]) != playerid - 1){//不可操縱對手的旗子
            printf("can't move\n");
            continue;
        }
        else {
            printf("Move to which direction (0, 1, 2, 3 for up, down, left, and right): ");
            scanf("%d", &move);
            int x, y;
            x = num1 + movingX[move];//new position
            y = num2 + movingY[move];

            if (x < 0 || y < 0 || x > 3 || y > 7) {
                continue;
            }
            if (board[x][y] == 0 || (rank(board[num1][num2]) == 0 && rank(board[x][y]) == 8) || (rank(board[num1][num2]) == 8 && rank(board[x][y]) == 0)){//兵吃將
                    board[x][y] = board[num1][num2];//move the chess
                    board[num1][num2] = 0;          //replace original chess with blank
                }
            else if(board[x][y] == 0 ||(color(board[num1][num2]) != color(board[x][y]) && rank(board[num1][num2]) >= rank(board[x][y]) &&!(rank(board[num1][num2]) == 7 && rank(board[x][y]) == 0))){////下一格是空的or不同色且rank更大
                    board[x][y] = board[num1][num2];//move the chess
                    board[num1][num2] = 0;          //replace original chess with blank
            }
            else
                continue;
        }
        playerid = 3 - playerid;// Update playerid using modulo to alternate between 1 and 2
    }

    return 0;
}
