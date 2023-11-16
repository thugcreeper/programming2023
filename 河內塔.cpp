#include<stdio.h> 
void hanoi(int n, char start, char goal, char other){
    if (n == 1){
        printf("±q %c ¬W²¾¨ì %c ¬W\n", start, goal);
    }
    else {
        hanoi(n-1, start, other, goal);//call function move n-1plate from start to other
        hanoi( 1 , start, goal, other);//call function move 1plate from start to goal
        hanoi(n-1, other, goal, start);//call function move n-1plate from goal to start
    }
}
int main(){
    hanoi(5, 'A', 'C', 'B');
    return 0;
}
