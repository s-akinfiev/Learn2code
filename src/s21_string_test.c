#include "s21_string.h"

void s21_strlen_test(const char *str_test, size_t l);

int main(void) {
#ifdef STRLEN
    s21_strlen_test("hi!", 3);
    s21_strlen_test("", 0);
    s21_strlen_test(" ", 1);
    s21_strlen_test("\0", 0);
    s21_strlen_test("!@#$\%^&*()_+~<>?\":{}", 20);
#endif

    printf("%d", s21_strcmp("ABC", "ABC"));
}

void s21_strlen_test(const char *str_test, size_t l) {
    printf("%s\t%ld\t", str_test, s21_strlen(str_test));
    if ((s21_strlen(str_test) == l))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}