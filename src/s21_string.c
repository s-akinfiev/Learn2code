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
