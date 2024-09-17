#include <stdio.h>

int main(void) {
    int a = 0, b = 0, res;

    scanf("%d %d", &a, &b);
    if (a > b)
        res = a;
    else
        res = b;

    while (res % a || res % b) res++;

    printf("%d\n", res);

    return 0;
}