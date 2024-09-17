#include <stdio.h>

int main(void) {
    int a = 0, k = 0;
    int res;

    scanf("%d %d", &a, &k);
    res = 1;

    while (k > 0) {
        if (k % 2 == 1) {
            res = res * a;
        }
        a = a * a;
        k = k / 2;
    }
    printf("%d\n", res);

    return 0;
}