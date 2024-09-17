#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"
#include "stack.h"

void parse(char *input, struct stack **root, char *outstr) {
    while (*input != '\0') {
        char token[100] = " ";
        int token_index = 0;

        if (*input >= '0' && *input <= '9') {
            while (*input >= '0' && *input <= '9') {
                token[token_index] = *input;
                token_index++;
                input++;
            }
            token[token_index] = '\0';
            strcat(outstr, token);
            strcat(outstr, " ");

        } else if (*input == '+' || *input == '*' || *input == '/' || *input == '-') {
            token[token_index] = *input;
            token_index++;
            input++;

            token[token_index] = '\0';

            while (*root != NULL && getprior(*token) <= getprior(*((*root)->data))) {
                strcat(outstr, (*root)->data);
                strcat(outstr, " ");
                *root = pop(*root);
            }
            *root = push(*root, token);

        } else if (*input == '(') {
            token[token_index] = *input;
            token_index++;
            input++;

            token[token_index] = '\0';
            *root = push(*root, token);

        } else if (*input == ')') {
            while (*root != NULL && (*root)->data[0] != '(') {
                strcat(outstr, (*root)->data);
                strcat(outstr, " ");
                *root = pop(*root);
            }
            if (*root != NULL) {
                *root = pop(*root);
            }
            input++;

        } else if (strncmp(input, "sin", 3) == 0 || strncmp(input, "cos", 3) == 0 ||
                   strncmp(input, "ln", 2) == 0 || strncmp(input, "tan", 3) == 0 ||
                   strncmp(input, "ctg", 3) == 0 || strncmp(input, "sqrt", 4) == 0) {
            int function_length = (*input == 'l') ? 2 : ((*input == 's' && *(input + 1) == 'q') ? 4 : 3);
            for (int i = 0; i < function_length; i++) {
                token[token_index] = *input;
                token_index++;
                input++;
            }
            token[token_index] = '\0';
            while (*root != NULL && getprior(*token) <= getprior(*((*root)->data))) {
                strcat(outstr, (*root)->data);
                strcat(outstr, " ");
                *root = pop(*root);
            }
            *root = push(*root, token);
        } else if (*input == 'x') {
            token[token_index] = *input;
            token_index++;
            input++;

            token[token_index] = '\0';
            strcat(outstr, token);
            strcat(outstr, " ");
        }
        // token_index = 0;
    }
    while (*root != NULL && (*root)->next != NULL) {
        strcat(outstr, (*root)->data);
        strcat(outstr, " ");
        *root = pop(*root);
    }
}

int getprior(char operator) {
    int priority;

    switch (operator) {
        case '+':
            priority = 1;
            break;
        case '-':
            priority = 1;
            break;
        case '*':
            priority = 2;
            break;
        case '/':
            priority = 2;
            break;
        case 's':
            priority = 3;
            break;
        case 'c':
            priority = 3;
            break;
        case 'l':
            priority = 3;
            break;
        case 't':
            priority = 3;
            break;
        default:
            priority = 0;
            break;
    }
    return priority;
}

int main(void) {
    struct stack *root = init(" ");
    char raw_input[100];

    if (scanf("%99s", raw_input) == 1) {
        char outputstring[100];
        parse(raw_input, &root, outputstring);
        int y;
        if (scanf("%d", &y) == 1) {
            double rez = calc(outputstring, strnlen(outputstring, 100), y);

            printf("%lf", rez);

            for (struct stack *p = root; p->next != NULL; p = p->next) printf("%s ", p->data);
        } else
            printf("KURWA!!");
    } else
        printf("KURWA!!");

    destroy(root);

    return 0;
}
