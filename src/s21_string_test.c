#include "s21_string.h"

void s21_strlen_test(const char *str_test, size_t l);
void s21_strcmp_test(const char *str_a, const char *str_b, int x);

int main(void) {
#ifdef STRLEN
    s21_strlen_test("hi!", 3);
    s21_strlen_test("", 0);
    s21_strlen_test(" ", 1);
    s21_strlen_test("\0", 0);
    s21_strlen_test("!@#$\%^&*()_+~<>?\":{}", 20);
#endif

#ifdef STRCMP
    s21_strcmp_test("ABC", "abc", -1);
    s21_strcmp_test(" ", " ", 0);
    s21_strcmp_test("!@#$\%^&*()_+~<>?\\", "!@#$\%^&*()_+~<>?\\", 0);
    s21_strcmp_test("", " ", -1);
    s21_strcmp_test(" A", "A", -1);
    s21_strcmp_test("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz", 0);
#endif
}

void s21_strlen_test(const char *str_test, size_t l) {
    printf("%s\t%ld\t", str_test, s21_strlen(str_test));
    if ((s21_strlen(str_test) == l))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcmp_test(const char *str_a, const char *str_b, int x) {
    printf("%s\t%s\t%d\t", str_a, str_b, s21_strcmp(str_a, str_b));
    if ((s21_strcmp(str_a, str_b) == x))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");   
}
