#include <stdio.h>
#include <stdlib.h>

// 1, если k чётное и −1, если k нечётное.

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", (abs(x % 2) + 1) - 3 * abs(x % 2));
    return 0;
}