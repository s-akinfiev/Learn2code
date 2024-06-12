#include <stdio.h>
#define NMAX 10

int input(int *array, int *length, int *shift);
void output(int *array, int length);
void cycle_shift(int *array, int length, int shift);

int main(void) {
    int n = 0, k = 0, arr[NMAX];
    if (input(arr, &n, &k) == 0) {
        if (k >= 0) {
            cycle_shift(arr, n, k);
        } else {
            cycle_shift(arr, n, n - (k * -1));
        }
        output(arr, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *array, int *length, int *shift) {
    int rusult = 0;
    double tmp = 0.0;
    *length = 0;
    if (scanf("%lf", &tmp) != 1) {
        rusult = 1;
    } else if ((int)tmp != tmp) {
        rusult = 1;
    } else {
        *length = (int)tmp;
    }
    if (*length <= NMAX && *length > 0) {
        for (int *p = array; p - array < *length; p++) {
            if (scanf("%lf", &tmp) != 1) {
                rusult = 1;
            } else if ((int)tmp != tmp) {
                rusult = 1;
            } else {
                *p = (int)tmp;
            }
        }
        if (rusult == 0 && scanf("%lf", &tmp) != 1) {
            rusult = 1;
        } else if ((int)tmp != tmp) {
            rusult = 1;
        } else {
            *shift = (int)tmp;
        }
    }
    return rusult;
}

void output(int *array, int length) {
    for (int *p = array; p - array < length; p++) {
        if (p - array != length - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

void cycle_shift(int *array, int length, int shift) {
    for (int i = 0; i < shift; i++) {
        int tmp = *array;
        for (int *p = array; p - array < length - 1; p++) {
            *p = *(p + 1);
        }
        *(array + (length - 1)) = tmp;
    }
}
