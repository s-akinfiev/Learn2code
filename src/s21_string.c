#include "s21_string.h"

size_t s21_strlen(const char *str) {
    size_t len = 0;
    const char *pointer = str;

    while (*pointer != '\0') {
        pointer++;
        len++;
    }
    return len;
}

int s21_strcmp(const char *str_a, const char *str_b) {
    while (*str_a && str_b && (*str_a == *str_b)) {
        str_a++;
        str_b++;
    }
    return *str_a == *str_b ? 0 : (*str_a > *str_b ? 1 : -1);
}

char *s21_strcpy(char *destination, const char *source) {
    int i = 0;
    while (source[i]) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

char *s21_strcat(char *destination, const char *append) {
    char *begin = destination;
    destination = destination + s21_strlen(destination);
    while (*append) {
        *destination = *append;
        destination++;
        append++;
    }
    *(destination++) = '\0';
    return begin;
}