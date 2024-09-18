//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

#include <stdio.h>


int render_frame (){
    int field_width = 80;
    int field_height = 25;

    int paddle_left_y = 2;
    int paddle_right_y = 23;

    int ball_x = 15;
    int ball_y = 10;
    
    char cell_content = ' ';

    printf("\e[1;1H\e[2J");

    for (int y = 0; y <= field_height; y++){
        for (int x = 0; x <= field_width; x++) {
            
            if (y == 0 || y == field_height)
                cell_content = '-';
            else if (x == 0 || x == field_width)
                cell_content = '|';
            else if (x == 1 && (y == paddle_left_y || y == paddle_left_y -1 || y == paddle_left_y + 1))
                cell_content = ']';
            else if (x == 79 && (y == paddle_right_y || y == paddle_right_y -1 || y == paddle_right_y + 1))
                cell_content = '[';
            else if (x == ball_x && y == ball_y)
                cell_content = '*';
            else if (y < field_height && x < field_width)
                cell_content = ' ';

            printf("%c", cell_content);
            cell_content = ' ';
      }
      printf("%c\n", cell_content);
    }
    return 0;
}

int main(void) {
    render_frame();
    return 0;
}