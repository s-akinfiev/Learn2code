#include <stdio.h>

int main(void) {
    int k, x, res = 1;

    scanf("%d%d", &k, &x);

    switch (k) {
        case 4:
            res *= x / 1000 % 10;
        case 3:
            res *= x / 100 % 10;
        case 2:
            res *= x / 10 % 10;
        case 1:
            res *= x % 10;

            printf("%d", res);
            break;
        default:
            printf("ERROR!");
    }

    return 0;
}