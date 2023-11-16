#include <stdio.h>

int main() {
    int data, interval, score, upper_range, lower_range = 0;
    int scoreboard[100] = {0};

    printf("Number of students: ");
    scanf("%d", &data);
    printf("Score interval: ");
    scanf("%d", &interval);
    
    while (interval <= 1) {
        printf("Input a number greater than 1. Try again: ");
        scanf("%d", &interval);
    }

    for (int repeat = 0; repeat < data; repeat++) {
        printf("Student#%d's score: ", repeat + 1);
        scanf("%d", &score);
        scoreboard[score / 10]++;			//可以不需要用for迴圈檢查是否在區間 
    }
    printf("\nScoreRange People BarChart\n");

    for (int i = 0; i < 100; i++) {
        lower_range = i * interval;
        upper_range = lower_range + interval - 1;
        if (lower_range <= 100) {
            printf("%3d ~ %3d %5d   ", lower_range, upper_range, scoreboard[i]);

            // Print a bar chart
            for (int j = 0; j < scoreboard[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}

