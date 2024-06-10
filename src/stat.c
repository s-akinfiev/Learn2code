#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
/*double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);
*/
int main()
{
    int n, data[NMAX];
    if (input(data, &n) == 1){
    output(data, n);
    printf("\nmax is %d", max(data, n));
    printf("\nmin is %d", min(data, n));
    }
/*  output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
*/
    else
    printf("n/a");
    return 0;
}


int input(int *a, int *n) {
    char term = '\n';

    if (scanf("%d%c", n, &term) == 2 && *n > 0 && *n <= NMAX && term == '\n') {
        for (int *p = a; p - a < *n; p++) {
            if ((scanf("%d%c", p, &term)) != 2 || !(term == '\n' || term == ' '))
                return 0;
        }
    }
    else
    return 0;

    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1)
            printf("%d ", *p);
        else
            printf("%d", *p);
    }
}

int max(int *a, int n) {
    int result = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p > result)
        result = *p;
    }
    return result;
}

int min(int *a, int n) {
    int result = *a;

    for (int *p = a; p - a < n; p++) {
        if (*p < result)
        result = *p;
    }
    return result;
}


