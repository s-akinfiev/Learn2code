#ifndef STACK_H
#define STACK_H

struct token {
    char data[100];
};


struct stack {
    struct token data;
    struct stack *next;
};

struct stack *init(struct token *data);
struct stack *push(struct stack *top, int data);
struct stack *pop(struct stack *top);
struct stack *read(struct stack *top);
void destroy(struct stack *top);

#endif