#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 0) {
        ;
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    int input_error = 0;

    if (scanf("%d", n) == 1 && *n > 0 && *n <= NMAX)
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d", p) == 1)
                ;
            else
                input_error = 1;
    else
        input_error = 1;

    return input_error;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1)
            printf("%d ", *p);
        else
            printf("%d", *p);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
