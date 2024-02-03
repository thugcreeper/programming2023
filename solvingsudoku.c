#include<stdio.h>
int puzzle[9][9]={};
int candidate[9][9][10]={};
void printGameField(int puzzle[9][9]){
int i,j;
    printf("╔══╤══╤══╦══╤══╤══╦══╤══╤══╗\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if(j%3==0)
                printf("║ %d", puzzle[i][j]);
            else
                printf("│ %d", puzzle[i][j]);
        }
        printf("║\n");
        if(i<8&&i%3==2)
        printf("╟══┼══┼══╫══┼══┼══╫══┼══┼══╢\n");
        else if(i<8)
        printf("╟──┼──┼──╫──┼──┼──╫──┼──┼──╢\n");
    }
    printf("╚══╧══╧══╩══╧══╧══╩══╧══╧══╝\n");
}
void inputQuiz(int puzzle[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            puzzle[i][j]=0;
            scanf("%1d",&puzzle[i][j]);// 將所有格子都設為 0, 再由鍵盤讀入題目
        }
    }
}
void removeCandidate(int i, int j, int value) { // 當 puzzle[i][j] 確定填入 value, 其他格就不能填
    for(int row=0;row<9;row++){//同一列之 candidate[??][??][value] 改為 0 or false
        candidate[i][row][value]=0;
    }
    for(int col=0;col<9;col++){//同一欄之 candidate[??][??][value] 改為 0 or false
        candidate[col][j][value]=0;
    }
    for(int a=i/3*3;a<i/3*3+3;a++){
        for(int b=j/3*3;b<j/3*3+3;b++){//同一宮之 candidate[a][b][value] 改為 0 or false // a, b 的起終範圍可由 i, j 算出
            candidate[a][b][value]=0;
        }
    }
    for(int a=1;a<=9;a++){
        candidate[i][j][a]=0;//puzzle[i][j] 之 candidate[i][j][???] 全改為 0 or false
    }
}
void startFindSolution() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<10;k++){
                candidate[i][j][k]=1;
            }
        }
    }
    for(int i=0;i<9;i++){//檢查每一格 puzzle[i][j],puzzle[i][j] 有值的時候呼叫 removeCandidate(...)
        for(int j=0;j<9;j++){
            if(puzzle[i][j]>0)
                removeCandidate(i,j,puzzle[i][j]);
        }
    }
}
int solveBySingleSol() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){//檢查每一格 puzzle[i][j]
            if(puzzle[i][j]==0){//當 puzzle[i][j] 沒有值而且只有一種填法,puzzle[i][j] 填入值,呼叫 removeCandidate(...)
                int count =0,ans;
                for(int k=1;k<=9;k++){
                    if(candidate[i][j][k]>0){
                        count++;
                        ans=k;
                    }
                }
                if(count==1){
                    puzzle[i][j]=ans;
                    removeCandidate(i, j, ans);
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    inputQuiz(puzzle);
    printGameField(puzzle);
    startFindSolution();
    int yes = 1;
    while (yes > 0) {
        yes = 0;
        yes += solveBySingleSol();
        // yes += otherSolution(); // add other solutions in the future
    }
    printGameField(puzzle);
    return 0;
}
