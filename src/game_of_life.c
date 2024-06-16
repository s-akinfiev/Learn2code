#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 25
#define WIDTH 80

int next_generation(int filed[HEIGHT][WIDTH]);
int count_neighbours(int pole[HEIGHT][WIDTH], int a, int b);
int life_or_death(int pole[HEIGHT] [WIDTH], int a,int b);
void render(int field[HEIGHT][WIDTH]);
int end_game(int generation[HEIGHT][WIDTH], int next_generation[HEIGHT][WIDTH]);


int main() {
    int field[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            if ((x + y) % 4 == 0)
                field[y][x] = 1;
            else
                field[y][x] = 0;

    
    render(field);

    return 0;
}

int next_generation(int field[HEIGHT][WIDTH]) {
    int temp[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            temp[y][x] = life_or_death(field, y, x);
        }
    }

    field = temp;

    return 0;
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

int end_game(int generation[HEIGHT][WIDTH], int next_generation[HEIGHT][WIDTH]) {
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


int count_neighbours(int pole[HEIGHT][WIDTH], int a, int b) {
    int sosedi = 0;
    
    for (int x = a-1; x <= a+1; x++) {
        for (int y = b-1; y < b+1; y++) {
            if (x != a || y != b) {
                int ryad=(a+x+WIDTH)% WIDTH; //зацикленность по горизонтали
                int stolbik=(b+y+HEIGHT)%HEIGHT; //зацикленность по вертикали
                sosedi += pole[ryad][stolbik];
            }
        }
        
        
    }
    return sosedi;
}

int life_or_death(int pole[HEIGHT] [WIDTH], int a,int b){
int sosedi=count_neighbours(pole,a,b); 
int life_flag;       
        if (sosedi<2 || sosedi>3){
            life_flag=0; // смерть клетки
        }
        else if (sosedi==3){
            life_flag=1; //жизнь
        }
        else{
            life_flag=0; // как было пусто
        }
        return life_flag;
        }
