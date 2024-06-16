#include <stdio.h>
#define height 80
#define width 25

int count_neighbours(int pole[width][height], int a, int b) {
    int sosedi = 0;

    for (int x = -1; x <= 1; x++) {
        for (int y = -1, y < 1, y++) {
            if (x != 0 || y != 0) {
                    int ryad=(a+x+width)% width); //зацикленность по горизонтали
                    int stolbik=(b+y+height)%height); //зацикленность по вертикали
                    sosedi += pole[ryad][stolbik];
            }
        }

        return sosedi;
    }
