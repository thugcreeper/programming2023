#include<stdio.h>
void printGameField(){
int i,j;
int puzzle[9][9]={};
puzzle[0][0] = 5; puzzle[0][1] = 3; puzzle[0][4] = 7;
puzzle[1][0] = 6; puzzle[1][3] = 1; puzzle[1][4] = 9; puzzle[1][5] = 5;
puzzle[2][1] = 9; puzzle[2][2] = 8; puzzle[2][7] = 6;
puzzle[3][0] = 8; puzzle[3][4] = 6; puzzle[3][8] = 3;
puzzle[4][0] = 4; puzzle[4][3] = 8; puzzle[4][5] = 3; puzzle[4][8] = 1;
puzzle[5][0] = 7; puzzle[5][4] = 2; puzzle[5][8] = 6;
puzzle[6][1] = 6; puzzle[6][6] = 2; puzzle[6][7] = 8;
puzzle[7][3] = 4; puzzle[7][4] = 1; puzzle[7][5] = 9; puzzle[7][8] = 5;
puzzle[8][4] = 8; puzzle[8][7] = 7; puzzle[8][8] = 9;
    printf("שÝשששששחשששששחשששששÞשששששחשששששחשששששÞשששששחשששששחששששש‗\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if(j%3==0)
                printf("שר %d", puzzle[i][j]);
            else
                printf("¢x %d", puzzle[i][j]);
        }
        printf("שר\n");
        if(i<8&&i%3==2)
        printf("שעשששש¢qשששש¢qשששששףשששש¢qשששש¢qשששששףשששש¢qשששש¢qשששששפ\n");
        else if(i<8)
        printf("שע¢w¢w¢q¢w¢w¢q¢w¢wשף¢w¢w¢q¢w¢w¢q¢w¢wשף¢w¢w¢q¢w¢w¢q¢w¢wשפ\n");
    }
    printf("שדשששששםשששששםשששששהשששששםשששששםשששששהשששששםשששששםשששששו");
}
int main(){
    printGameField();
    return 0;
}
