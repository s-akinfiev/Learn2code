#include <math.h>
#include <stdio.h>

int devbydiff(int n, int d) {
    int r = 0;

    while (n >= d) {
        n = n - d;
        r += 1;
    }

    return n;
 }

_Bool 

int main(void) {
    int a = 0;
    char term = ' ';
    if (scanf("%d%c", &a, &term) == 1 || (term == '\n')) {
        printf("%d", devbydiff(200, 3));

    } else {
        printf("n/a");
    }
}