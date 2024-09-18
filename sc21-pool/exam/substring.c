#include <stdio.h>
#include <string.h>

int main(void) {

    char string[100];
    char *p = string;
    char target[100];

    fgets(string, sizeof(string), stdin);
    fgets(target, sizeof(target), stdin);

    string[strcspn(string, "\n")] = '\0';
    target[strcspn(target, "\n")] = '\0';

    char *t = strstr(string, target);




     

    return 0;
}