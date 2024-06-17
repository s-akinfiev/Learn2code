#include "data_stat.h"

#include <math.h>

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

double mean(double *a, int n) {
    double result = 0;

    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    return result / n;
}

double variance(double *a, int n) {
    double mean_forall = mean(a, n);
    double sq_sum = 0.;
    for (int i = 0; i < n; i++) {
        sq_sum += pow(a[i] - mean_forall, 2);
    }
    return sq_sum / n;
}