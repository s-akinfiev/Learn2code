#include <stdio.h>

int main(void) {
    int m, d;

    scanf("%d%d", &m, &d);  // считываем целое значение в переменную age

    switch (m) {
        case 12:
            d += 30;
        case 11:
            d += 31;
        case 10:
            d += 30;
        case 9:
            d += 31;
        case 8:
            d += 31;
        case 7:
            d += 30;
        case 6:
            d += 31;
        case 5:
            d += 30;
        case 4:
            d += 31;
        case 3:
            d += 28;
        case 2:
            d += 31;
        case 1:
            d += 0;
            printf("%d", d);
            break;
        default:
            printf("ERROR!");
    }

    return 0;
}