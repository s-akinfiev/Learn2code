#include "data_stat.h"

double max(double *a, int n) {
    double result = *a;

    for (int i = 0; i < n; i++) {
        if (a[i] > result) result = a[i];
    }
    return result;
}

double min(double *a, int n) {
    double result = *a;

    for (int i = 0; i < n; i++) {
        if (a[i] < result) result = a[i];
    }
    return result;
}