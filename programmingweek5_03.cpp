#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    int ans;
    while (a != 0 && b != 0) {
        ans = a % b;
        a = b;
        b = ans;		
    }
    return a;	//return 程そ计
}

int main() {
    const double pi = 3.14159265358979323846;
    int n, s, t, common;
    printf("n = ");
    scanf("%d", &n);
	printf("x = 0 PI, sin(x) = %f, cos(x) = %f\n",sin(pi*0), cos(pi*0));
    for (int k = 1; k <= 2 * n; k++) {
        common = gcd(k, n);			//程そ计 
        s = k / common;
        t = n / common;
        double x = k / (double)n;
        if(s%t == 0)
        printf("x = %d PI, sin(x) = %f, cos(x) = %f\n", s, sin(pi * x), cos(pi * x));
        else
        printf("x = %d/%d PI, sin(x) = %f, cos(x) = %f\n", s, t, sin(pi * x), cos(pi * x));
    }

    return 0;
}

