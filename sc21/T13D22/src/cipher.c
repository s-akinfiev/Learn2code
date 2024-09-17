#include <dirent.h>
#include <stdio.h>
#include <string.h>

int fileout(char *filename, char *filecontent);
int fileappend(char *filename, char *filecontent);
void caesar(char *text, int shift);
int cipher(char *filename);
int wipe(char *filename);

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
            case 3:
                if (cipher("../src/ai_modules/m1.c") != 0) {
                } else
                    printf("n/a\n");
                if (cipher("../src/ai_modules/m2.c") != 0) {
                } else
                    printf("n/a\n");

                if (wipe("../src/ai_modules/m1.h") != 0) {
                } else
                    printf("n/a\n");
                if (wipe("../src/ai_modules/m2.h") != 0) {
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
    int operation_result = 0;
    if (filename != NULL) {
        FILE *file = fopen(filename, "r");
        if (getc(file) != EOF) {
            rewind(file);
            while (fgets(filecontent, 256, file) != NULL) {
                printf("%s\n", filecontent);
            }
            operation_result = 1;
        } else
            operation_result = 0;

        fclose(file);
    } else
        operation_result = 0;
    return operation_result;
}

int fileappend(char *filename, char *filecontent) {
    int operation_result = 0;
    if (filename != NULL) {
        FILE *file = fopen(filename, "r+");
        if (getc(file) != EOF) {
            rewind(file);
            fseek(file, 0, SEEK_END);
            fputs(filecontent, file);
            operation_result = 1;
        } else
            operation_result = 0;
        fclose(file);
    } else
        operation_result = 0;

    return operation_result;
}

void caesar(char *text, int shift) {
    for (int i = 0; text[i] != '\0' && text[i] != EOF; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

int cipher(char *filename) {
    int shift;
    int operation_result = 0;

    // printf("offset? ");
    scanf("%d", &shift);

    if (filename != NULL) {
        char text[10000];
        FILE *file = fopen(filename, "r");

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);
        fread(text, 1, file_size, file);
        text[file_size] = '\0';

        fclose(file);
        caesar(text, shift);

        file = fopen(filename, "w");
        fprintf(file, "%s", text);
        fclose(file);
        operation_result = 1;

    } else
        operation_result = 0;

    return operation_result;
}

int wipe(char *filename) {
    int operation_result = 0;

    if (filename != NULL) {
        FILE *file = fopen(filename, "w");
        fclose(file);
        operation_result = 1;
    } else
        operation_result = 0;

    return operation_result;
}