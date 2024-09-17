#include <stdio.h>
#include <stdlib.h>

#include "../DATA_LIBS/data_io.h"
#include "data_process.h"

int main(void) {
    int n;
    double *data;

    // Don`t forget to allocate memory !

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double *));

        input(data, n);

        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");

        free(data);
    } else
        printf("ERROR");
}
