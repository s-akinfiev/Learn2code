#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x;

    scanf("%d", &x);

    int a4 = (x % 10 + 3) % 10;
    int a3 = (x / 10 % 10 + 3) % 10;
    int a2 = (x / 100 % 10 + 3) % 10;
    int a1 = (x / 1000 % 10 + 3) % 10;

    printf("%d", a3 * 1000 + a4 * 100 + a1 * 10 + a2);

    return 0;
}