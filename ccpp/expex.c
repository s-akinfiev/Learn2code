#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fact(int x);
double expex(double x);

int main() {
    double n;
    scanf("%lf", &n);
    printf("%0.6lf\n%0.6lf", exp(n), expex(n));

    return 0;
}

int fact(int x) {
    int res = 1;
    for (int i = 1; i < x; i++)
        res += res * i;
    return res;
}

double expex(double x) {
    double res = 1;
    for (int i = 1; i < 6; i++)
        res += (double) ((pow(x, i)) / fact(i));
    return res;
}