#include <stdio.h>
#include <stdlib.h>

void out(int **data, int or);
void spiralfill(int **data, int or);

int main(void) {
    int order;

    scanf("%d", &order);

    int **matrix = (int **)malloc(order * sizeof(int *));
    for (int i = 0; i < order; i++) matrix[i] = (int *)malloc(order * sizeof(int));

    spiralfill(matrix, order);
    out(matrix, order);

    for (int i = 0; i < order; i++) free(matrix[i]);
    free(matrix);
}

void spiralfill(int **data, int or) {
    int i = 0;
    int j = 0;
    int count = 1;
    int limit = 0;

    while (limit < (or +1) / 2) {
        for (j = limit; j < or -limit; j++) data[limit][j] = count++;

        for (i = limit + 1; i < or -limit; i++) data[i][or - 1 - limit] = count++;

        for (j = or -2 - limit; j >= limit; j--) data[or - 1 - limit][j] = count++;

        for (i = or -2 - limit; i > limit; i--) data[i][limit] = count++;

        limit++;
    }
}

void out(int **data, int or) {
    for (int i = 0; i < or ; i++) {
        for (int j = 0; j < or ; j++) printf("%4d ", data[i][j]);
        printf("\n");
    }
}