/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int max(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int gotcha);
int sigma(double mean_v, double variance_v, int x);
int search_for_gold(int *a, int n, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        output_result(search_for_gold(data, n, mean(data, n), variance(data, n)));
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    char term = '\n';

    if (scanf("%d%c", n, &term) == 2 && *n > 0 && *n <= NMAX && term == '\n') {
        for (int *p = a; p - a < *n; p++) {
            if ((scanf("%d%c", p, &term)) != 2 || !(term == '\n' || term == ' ')) return 0;
        }
    } else
        return 0;

    return 1;
}

int max(int *a, int n) {
    int result = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p > result) result = *p;
    }
    return result;
}

double mean(int *a, int n) {
    double result = 0;

    for (int *p = a; p - a < n; p++) {
        result += *p;
    }
    return result / n;
}

double variance(int *a, int n) {
    double mean_forall = mean(a, n);
    double sq_sum = 0.;
    for (int *p = a; p - a < n; p++) {
        sq_sum += pow(*p - mean_forall, 2);
    }
    return sq_sum / n;
}

void output_result(int gotcha) { printf("%d", gotcha); }

int sigma(double mean_v, double variance_v, int x) {
    if (x <= mean_v + 3 * variance_v)
        return 1;
    else
        return 0;
}

int search_for_gold(int *a, int n, double mean_v, double variance_v) {
    int res = 0;
    for (int *p = a; p - a < n; p++) {
        if ((*p % 2) == 0 && *p >= mean_v && sigma(mean_v, variance_v, *p) == 1 && *p != 0) {
            res = *p;
            break;
        }
    }
    return res;
}