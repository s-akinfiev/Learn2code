#include <stdio.h>

int main(void) {
    int age, height, weight;
    double bov;
    char sex = ' ';

    scanf("%c %d%d%d", &sex, &age, &height, &weight);  // считываем целое значение в переменную age

    switch (sex) {
        case 'm':
            bov = 10 * weight + 6.25 * height - 5 * age + 5;
            break;
        case 'f':
            bov = 10 * weight + 6.25 * height - 5 * age - 161;
            break;
        default:
            printf("ERROR!");
            return 0;
    }

    printf("|  BMR  |\n");
    printf("|%7.2f|", bov);
    return 0;
}