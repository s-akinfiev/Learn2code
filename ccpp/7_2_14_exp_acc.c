#include <math.h>
#include <stdio.h>

int fact(int x);

int main(void) {
    double eps, e = 2.0;
    int k = 1;

    scanf("%lf", &eps);
    while (1. / fact(k) > eps) {
        k++;
        e += 1. / fact(k);
    }
    printf("%0.8f", e);

    return 0;
}

int fact(int x) {
    int res = 1;
    for (int i = 1; i < x; i++) res += res * i;
    return res;
}