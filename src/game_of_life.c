#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 25
#define WIDTH 80

void clean(int **matrix);
void allocate_memory(int ***matrix);
int next_generation(int ***field);
int check_life(int **field, int y, int x);
int life_or_death(int life, int neighbours);


int main() {
    return 0;
}

void clean(int **matrix) {
    for (int i = 0; i < HEIGHT; i++) free(matrix[i]);
    free(matrix);
}

void allocate_memory(int ***matrix) {
    *matrix = calloc(HEIGHT, sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        (*matrix)[i] = calloc(WIDTH, sizeof(int));
    }
}

int next_generation(int ***field) {
    int **temp;
    allocate_memory(&temp);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // temp[y][x] = life_or_death((*field)[y][x], check_life(*field, y, x));
        }
    }

    clean(*field);
    *field = temp;

    return 0;
}