#include<stdio.h>
int board[4][8] = { 0 };
char* chessname[2][9] ={{"卒","","","包","馬","車","象","士","將"},{"兵","","","炮","傌","俥","相","仕","帥"}};
int rank(int id){
    if(id>16)
        id -= 16;
    int k = id/2;//rank
    if(k<3)
        k = 0;
    return k;
}
int color(int id){
    if(id<=16)
        return 0;//black chess
    else
        return 1;//red chess
}

void gameInit() {
    board[0][2] = -8; // covered "馬"; print "●" instead
    board[0][3] = 8;  // uncovered "馬"
    board[1][7] = 32; // uncovered "仕"
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
    srand((unsigned int)time(NULL));
    system("chcp 65001 & cls"); // (for Windows users) force the command window to show unicode characters
    gameInit();
    printBoard();


    return 0;
}





