#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main(void) {
    int n;
    double *data;

    // Don`t forget to allocate memory !

    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)malloc(n * sizeof(double *));

        printf("LOAD DATA...\n");
        input(data, n);

        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");

        printf("\nSORTED NORMALIZED DATA:\n\t");
        if (normalization(data, n)) {
            sort(data, n);
            output(data, n);
        } else
            printf("ERROR");

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
        free(data);
    } else
        printf("ERROR");
}
