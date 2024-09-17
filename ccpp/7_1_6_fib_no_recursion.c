#include <stdio.h>

int main() {
    int k;
    int f = 1;
    int f1 = 0;
    int f2 = 0;
    scanf("%d", &k);
    for (int i = 1; i < k; ++i) {
        f2 = f1;
        f1 = f;
        f = f1 + f2;
    }
    printf("%d ", f);
    return 0;
}