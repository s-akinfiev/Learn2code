#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 1, если k чётное и −1, если k нечётное.

// int odd(int x) { return 3 * abs(x % 2) - (abs(x % 2) + 1); }

int main() {
    int x1, x2, x3, x4, x5;
    scanf("%d%d%d%d%d", &x1, &x2, &x3, &x4, &x5);
    printf("%d", (int)pow(x1, 2) + (int)pow(x2, 2) + (int)pow(x3, 2) + (int)pow(x4, 2) + (int)pow(x5, 2));
    return 0;
}