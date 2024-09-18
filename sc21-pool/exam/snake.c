#include <stdio.h>
#include <stdlib.h>

void out(int **data, int r, int c);
void snakefill(int **data, int r, int c);

int main(void) {
    int row;
    int col;

    scanf("%d %d", &row, &col);

    int **matrix = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++) matrix[i] = (int *)calloc(col, sizeof(int));

    snakefill(matrix, row, col);
    out(matrix, row, col);

    for (int i = 0; i < row; i++) free(matrix[i]);
    free(matrix);
}

void snakefill(int **data, int r, int c) {
    int count = 1;

    for (int i = 0; i < r; i++) {
        if (i % 2 == 0)
            for (int j = 0; j < c; j++) data[i][j] = count++;
        else
            for (int j = c - 1; j >= 0; j--) data[i][j] = count++;
    }
}

void out(int **data, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%4d ", data[i][j]);
        printf("\n");
    }
}