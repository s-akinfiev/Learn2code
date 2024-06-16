#include <stdio.h>
#define WIDTH 80
#define HEIGHT 25

void render(int field[HEIGHT][WIDTH]);
int end_game(int **generation, int **next_generation);

void render(int field[HEIGHT][WIDTH]) {
    char cell_content = ' ';
    
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < WIDTH + 2; i++) printf("-");
    printf("\n");
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (field[y][x] == 1) cell_content = 'o';
            printf("%c", cell_content);
            cell_content = ' ';
        }
        printf("|");
        printf("\n");
    }
    for (int i = 0; i < WIDTH + 2; i++) printf("-");
    printf("\n");
}

int end_game(int **generation, int **next_generation) {
    int end = 0;

     for (int y = 0; y < HEIGHT; y++) 
        for (int x = 0; x < WIDTH; x++)
            if (generation[y][x] != 0)  end = 1;
            
    if (end != 1) {
        for (int y = 0; y < HEIGHT; y++) 
            for (int x = 0; x < WIDTH; x++)
                if (generation[y][x] != next_generation[y][x]) end = 1;
    }
        

        return end;
    }

    int main(void) {
        int field[HEIGHT][WIDTH];

        for (int y = 0; y < HEIGHT; y++)
            for (int x = 0; x < WIDTH; x++)
                if ((x + y) % 4 == 0)
                    field[y][x] = 1;
                else
                    field[y][x] = 0;

        while (end_game(generation, next_generation) != 0)
        render(field);

        return 1;
    }
