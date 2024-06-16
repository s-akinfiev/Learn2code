#include <stdio.h>
#define height 80
#define width 25

// int height=80;
// int width=25;


int pole [width] [height]
for (int a=0; a<width; a++){
    for (int b=0; b<height; b++){
        sosedi=0;
        
        for (int x=-1; x<=1; x++){
            for (int y=-1, y<1, y++){
                if(x!=0 || y!=0){
                    int ryad=a+x;
                    int stolbik=b+y;
                    if(ryad>=0 && ryad<width && stolbik>=0 && stolbik < height){
                        sosedi+=pole[ryad] [stolbik];
                    }
                }
        }
    }
        if (sosedi<2 || sosedi>3) {
            nextpole [a][b]=0;
        }
        else if(sosedi==3){
            nextpole[a][b]=1;
        }
        else
        {
            nextpole[a][b]=pole[a][b];
        }
        }
}
