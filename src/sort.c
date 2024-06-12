#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void sorter(int *a, int n);

int main() {
    int n = 10;
    int data[n];

    if (input(data, &n) == 1) {
        sorter(data, n);
        output(data, n);
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    char term = '\n';

    for (int *p = a; p - a < *n; p++) {
        if ((scanf("%d%c", p, &term)) != 2 || !(term == '\n' || term == ' ')) return 0;
    }
    return 1;
}

void sorter(int *a, int n) {
    int tmp = 0;
    int swap_happened = 0;

    for (int *pi = a; pi - a < n; pi++) {
        swap_happened = 0;
        for (int *pj = a; pj - a < n - (pi - a) - 1; pj++) {
            if (*pj > *(pj + 1)) {
                tmp = *pj;
                *pj = *(pj + 1);
                *(pj + 1) = tmp;
                swap_happened = 1;
            }
        }
        if (swap_happened == 0) break;
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1)
            printf("%d ", *p);
        else
            printf("%d \n", *p);
    }
}