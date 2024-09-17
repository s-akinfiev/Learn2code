#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80

int next_generation(int filed[HEIGHT][WIDTH]);
int count_neighbours(int pole[HEIGHT][WIDTH], int a, int b);
int life_or_death(int pole[HEIGHT][WIDTH], int a, int b);
void render(int field[HEIGHT][WIDTH]);
int end_game(int generation[HEIGHT][WIDTH], int next_generation[HEIGHT][WIDTH]);
int change_speed(int speed, int key);
void get_initial(int field[HEIGHT][WIDTH]);

int main() {
    int field[HEIGHT][WIDTH], life = 1, speed = 50000;
    get_initial(field);
    initscr();
    start_color();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    timeout(50);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    int key = 0;

    while (life && key != 'q') {
        key = getch();
        speed = change_speed(speed, key);
        render(field);
        printw("Speed: %d\n", 11 - speed / 10000);
        refresh();
        usleep(speed);
        life = next_generation(field);
    }
    if (!life) {
        mvprintw(HEIGHT / 2, WIDTH / 2 - 2, "GAME END");
        refresh();
        getchar();
    }

    endwin();

    return 0;
}

void get_initial(int field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = 0;
        }
    }

    int y, x;
    while (scanf("%d %d%*[^\n]", &y, &x) == 2) {
        field[y][x] = 1;
        if (getchar() == 'q') break;
    }
    while (getchar() != '\n') {
    }
}

int next_generation(int field[HEIGHT][WIDTH]) {
    int temp[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            temp[y][x] = life_or_death(field, y, x);
        }
    }

    int end = end_game(temp, field);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = temp[y][x];
        }
    }

    return end;
}

void render(int field[HEIGHT][WIDTH]) {
    char cell_content = ' ';
    clear();
    for (int i = 0; i < WIDTH + 2; i++) printw("-");
    printw("\n");
    for (int y = 0; y < HEIGHT; y++) {
        printw("|");
        for (int x = 0; x < WIDTH; x++) {
            if (field[y][x] == 1) cell_content = 'o';
            attron(COLOR_PAIR(1));
            printw("%c", cell_content);
            attroff(COLOR_PAIR(1));
            cell_content = ' ';
        }
        printw("|\n");
    }
    for (int i = 0; i < WIDTH + 2; i++) printw("-");
    printw("\n");
}

int end_game(int generation[HEIGHT][WIDTH], int next_generation[HEIGHT][WIDTH]) {
    int end = 0;

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            if (generation[y][x] != 0) end = 1;

    if (end != 1) {
        for (int y = 0; y < HEIGHT; y++)
            for (int x = 0; x < WIDTH; x++)
                if (generation[y][x] != next_generation[y][x]) end = 1;
    }

    return end;
}

int count_neighbours(int field[HEIGHT][WIDTH], int y, int x) {
    int neighbours = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            int row = i, col = j;
            if (row < 0) row = HEIGHT + row;
            row = row % HEIGHT;
            if (col < 0) col = WIDTH + col;
            col = col % WIDTH;
            if ((i != y || j != x) && field[row][col]) neighbours++;
        }
    }
    return neighbours;
}

int life_or_death(int pole[HEIGHT][WIDTH], int a, int b) {
    int sosedi = count_neighbours(pole, a, b);
    int life_flag = 0;
    if (pole[a][b]) {
        if (sosedi >= 2 && sosedi <= 3) {
            life_flag = 1;  // жизнь
        }
    } else if (sosedi == 3) {
        life_flag = 1;  // жизнь
    }
    return life_flag;
}

int change_speed(int speed, int key) {
    if (key == 259 && speed > 10000) return speed - 10000;
    if (key == 258 && speed < 100000) return speed + 10000;
    return speed;
}