#ifndef STACK_H
#define STACK_H

struct stack {
    char data[10];
    struct stack *next;
};

struct stack *init(char *data);
struct stack *push(struct stack *top, char *data);
struct stack *pop(struct stack *top);
// struct stack *stread(struct stack *top);
void destroy(struct stack *top);

void parse(char *input, struct stack **root, char *outstr);
int getprior(char operator);
#endif