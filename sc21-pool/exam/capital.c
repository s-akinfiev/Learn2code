#include <stdio.h>

int main(void) {
    char input[100];
    char *first = input;
    char *p = input;
    fgets(input, sizeof(input), stdin);
    printf("%s\n", input);

    while (*p != '\0') {
        if ((*p >= 'a' && *p <= 'z') && (*(p - 1) == ' ' || p - first == 0)) {
            printf("%c", *p - 32);
        } else
            printf("%c", *p);

        p++;
    }

    return 0;
}