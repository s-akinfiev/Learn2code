#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int fact(int x);
double nepper(int x);

int main() {
    int n;
    scanf("%d", &n);
    printf("%0.5lf", nepper(n));

    return 0;
}

int fact(int x) {
    int res = 1;
    for (int i = 1; i < x; i++) res += res * i;
    return res;
}

double nepper(int x) {
    double res = 1;
    for (int i = 1; i < x; i++) res += (double)1 / fact(i);
    return res;
}