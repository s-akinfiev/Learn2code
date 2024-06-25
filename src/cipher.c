#include <stdio.h>
#include <string.h>

int fileout(char *filename, char *filecontent);
int fileappend(char *filename, char *filecontent);

int main(void) {
    char file_name[100];
    char file_content_read[256];
    char file_content_append[256];
    int command;

    while (scanf("%d", &command) != 0 && command != -1) switch (command) {
            case 1:
                scanf("%99s", file_name);
                if (fileout(file_name, file_content_read) != 0) {
                } else
                    printf("n/a\n");
                break;
            case 2:
                getchar();
                fgets(file_content_append, 256, stdin);
                file_content_append[strlen(file_content_append) - 1] = '\0';
                if (fileappend(file_name, file_content_append) != 0) {
                    fileout(file_name, file_content_read);
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
    if (filename != NULL) {
        FILE *file = fopen(filename, "r");
        if (getc(file) != EOF) {
            rewind(file);
            while (fgets(filecontent, 256, file) != NULL) {
                printf("%s\n", filecontent);
            }
            operaton_result = 1;
        } else
            operaton_result = 0;

        fclose(file);
    } else
        operaton_result = 0;
    return operaton_result;
}

int fileappend(char *filename, char *filecontent) {
    int operaton_result = 0;
    if (filename != NULL) {
        // char ch;
        FILE *file = fopen(filename, "r+");
        if (getc(file) != EOF) {
            rewind(file);
            fseek(file, 0, SEEK_END);
            fputs(filecontent, file);
            operaton_result = 1;
        } else
            operaton_result = 0;
        fclose(file);
    } else
        operaton_result = 0;

    return operaton_result;
}