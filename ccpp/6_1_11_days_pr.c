#include <stdio.h>

int main(void) {
    int k;

    scanf("%d", &k);

    switch ((int)(k >= 11 && k <= 14)) {
        case 1:
            printf("Мне %d лет", k);
            break;
        case 0:
            switch (k % 10) {
                case 1:
                    printf("Мне %d год", k);
                    break;
                case 2:
                case 3:
                case 4:
                    printf("Мне %d года", k);
                    break;
                default:
                    printf("Мне %d лет", k);
                    break;
            }
    }
    return 0;
}