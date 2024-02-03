#include<stdio.h>
void printGameField(int puzzle[9][9]){
int i,j;

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
void inputQuiz(int puzzle[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%1d",&puzzle[i][j]);
        }
    }
}
int main(){
    int puzzle[9][9]={};
    inputQuiz(puzzle);
    printGameField(puzzle);
    return 0;
}
