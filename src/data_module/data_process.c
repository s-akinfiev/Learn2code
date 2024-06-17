#include "data_process.h"

#include <math.h>

#include "../DATA_LIBS/data_stat.h"

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if (fabs(size) >= EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }

    return result;
}

void sort(double *a, int n) {
    double tmp;

    for (int i = 0; i < n; i++) {
        int swap_happened = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swap_happened = 1;
            }
        }
        if (!swap_happened) break;
    }
}
