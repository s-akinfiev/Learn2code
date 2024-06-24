#include <stdio.h>

int fileout(char *filename, char *filecontent);

int main(void) {
    char file_name[100];
    char file_content[256];
    int command;

    while (scanf("%d", &command) != 0 && command != -1) switch (command) {
            case 1:
                scanf("%s", file_name);
                if (fileout(file_name, file_content) != 0) {
                } else
                    printf("n/a\n");
                break;
            default:
                printf("n/a\n");
                break;
        }
    if (!(command == -1)) printf("n/a\n");

    return 0;
}

int fileout(char *filename, char *filecontent) {
    int operaton_result = 0;
    FILE *file = fopen(filename, "r");
    if (file != NULL && filename && getc(file) != EOF) {
        rewind(file);
        while (fgets(filecontent, 256, file) != NULL) {
            printf("%s\n", filecontent);
        }
        fclose(file);
        operaton_result = 1;
    } else
        operaton_result = 0;

    return operaton_result;
}