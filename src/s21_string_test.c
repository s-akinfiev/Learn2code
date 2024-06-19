#include "s21_string.h"

void s21_strlen_test(const char *str_test, size_t l);
void s21_strcmp_test(const char *str_a, const char *str_b, int x);
void s21_strcpy_test(char *destination, const char *source, const char *check);
void s21_strcat_test(char *destination, const char *append, size_t len);

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

#ifdef STRCPY
    char test[100] = " ";
    s21_strcpy_test(test, "qwerty", "qwerty");
    s21_strcpy_test(test, "12345", "12345");
    s21_strcpy_test(test, " ", " ");
    s21_strcpy_test(test, "", "");
    s21_strcpy_test(test, "-091фыв[]{}<>", "-091фыв[]{}<>");
#endif

#ifdef STRCAT
    char test_cat[100] = "ABC";
    s21_strcat_test(test_cat, "QWERTY", 9);
    s21_strcat_test(test_cat, "12", 11);
    s21_strcat_test(test_cat, "", 11);
    s21_strcat_test(test_cat, " ", 12);
    s21_strcat_test(test_cat, "^%$@#$@!", 20);
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

void s21_strcpy_test(char *destination, const char *source, const char *check) {
    printf("%s\t%s\t%s\t", destination, source, s21_strcpy(destination, source));
    if (s21_strcmp(s21_strcpy(destination, source), check) == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}

void s21_strcat_test(char *destination, const char *append, size_t len) {
    char *res_cat = s21_strcat(destination, append);
    printf("%s\t%s\t%s\t", destination, append, res_cat);
    if (s21_strlen(res_cat) == len)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
}