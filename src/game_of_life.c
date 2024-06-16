#include <stdio.h>
#define height 80
#define width 25

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
   
    
