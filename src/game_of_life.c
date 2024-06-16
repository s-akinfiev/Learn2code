#include <stdio.h>

#define HEIGHT 80
#define WIDTH 25

int count_neighbours(int pole[width][height], int a, int b);
int life_or_death(int pole[width] [height], int a,int b);
void render(int field[HEIGHT][WIDTH]);
int end_game(int **generation, int **next_generation);

int main() {
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


int count_neighbours(int pole[width][height], int a, int b) {
    int sosedi = 0;
    
    for (int x = a-1; x <= a+1; x++) {
        for (int y = b-1; y < b+1; y++) {
            if (x != a || y != b) {
                int ryad=(a+x+width)% width; //зацикленность по горизонтали
                int stolbik=(b+y+height)%height; //зацикленность по вертикали
                sosedi += pole[ryad][stolbik];
            }
        }
        
        
    }
    return sosedi;
}

int life_or_death(int pole[width] [height], int a,int b){
int sosedi=count_neighbours(pole,a,b); 
int life_flag;       
        if (sosedi<2 || sosedi>3){
            life_flag=0; // смерть клетки
        }
        else if (sosedi==3){
            life_flag=1; //жизнь
        }
        else{
            life_flag=0 // как было пусто
        }
        return life_flag
        }
    }
