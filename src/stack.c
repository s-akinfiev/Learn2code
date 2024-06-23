#include "stack.h"

#include <stdlib.h>
#include <string.h>

struct stack *init(char *data) {
    struct stack *top = malloc(sizeof(struct stack));
    strcpy(top->data, data);
    top->next = NULL;
    return top;
}

struct stack *push(struct stack *top, char *data) {
    struct stack *new_top = malloc(sizeof(struct stack));
    strcpy(new_top->data, data);
    new_top->next = top;
    return new_top;
}

struct stack *pop(struct stack *top) {
    struct stack *new_top = NULL;
    if (top != NULL) {
        new_top = top->next;
        free(top);
    }
    return new_top;
}

/* struct stack *stread(struct stack *top) {
    if (top != NULL)
        return (top);
    else
        return NULL;
} */

void destroy(struct stack *top) {
    struct stack *current = top->next;
    while (current != NULL) {
        free(top);
        top = current;
        current = top->next;
    }
    free(top);
}