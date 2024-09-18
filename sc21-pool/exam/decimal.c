#include <math.h>
#include <stdio.h>

int main(void) {
    int a;

    if (scanf("%d", &a) == 1) {
        for (int i = 1; i <= 3; i++) {
            if (a >= 0)
                printf("%d", (a % (int)pow(10, i)) / (int)pow(10, i - 1));
            else {
                a = -a;
                printf("-%d", (a % (int)pow(10, i)) / (int)pow(10, i - 1));
            }
        }

    } else
        printf("n/a");
}