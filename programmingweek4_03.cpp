#include <stdio.h>

int main() {
    int x[100];
    int y[100];
    int time, inputnum, x1, y1, a, b, c, r, s, t, n;
    int i;

    printf("How many sets of test data: ");
    scanf("%d", &inputnum);

    while (time < inputnum) {
        printf("\n");
        printf("x1 = ");		scanf("%d", &x1);    
        printf("y1 = ");		scanf("%d", &y1);  
        printf("a = ");			scanf("%d", &a);
        printf("b = ");			scanf("%d", &b);    
        printf("c = ");			scanf("%d", &c);   
        printf("r = ");			scanf("%d", &r);       
        printf("s = ");			scanf("%d", &s);        
        printf("t = ");			scanf("%d", &t);   
        printf("n = ");			scanf("%d", &n);
        

        x[0] = x1;	//x1 =1
        y[0] = y1;	//y1 =1

        for (i = 0; i < n; i++) {
            x[i+1] = a * x[i] + b * y[i] + c;
            y[i+1] = r * x[i] + s * y[i] + t;
            printf("n = %d, (x, y) = (%d, %d)\n", i+1, x[i], y[i]);
        }

        time++;  // 增加 time 的值，避免無窮迴圈
    }

    return 0;
}

