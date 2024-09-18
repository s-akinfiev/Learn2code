#include <math.h>
#include <stdio.h>

int counter(int a);

int main(void) {
    int a;
    int min = 9;
    int max = 0;

    if (scanf("%d", &a) == 1) {
        printf("count is - %d\n", counter(a));

        for (int i = 1; i <= counter(a); i++) {
            if (max < (a % (int)pow(10, i) / (int)pow(10, i - 1)))
                max = (a % (int)pow(10, i) / (int)pow(10, i - 1));
        }
        for (int i = 1; i <= counter(a); i++) {
            if (min > (a % (int)pow(10, i) / (int)pow(10, i - 1)))
                min = (a % (int)pow(10, i) / (int)pow(10, i - 1));
        }

        printf("max is %d\n", max);
        printf("min is %d", min);

    } else
        printf("n/a");

    return 0;
}

int counter(int a) {
    int j = 0;

    while ((a / (int)(pow(10, j)) > 0)) {
        j++;
    }

    return j;
}