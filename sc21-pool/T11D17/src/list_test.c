#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST_DOOR_COUNT 5

void add_door_test(struct node* elem, const struct door* new_door, int x);
void remove_door_test(struct node* elem, struct node* root, int x);

int main(void) {
    struct door doors[TEST_DOOR_COUNT] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};
    struct node* root = init(&doors[0]);

    add_door_test(root, &doors[1], 1);
    remove_door_test(find_door(2, root), root, 0);

    destroy(root);
    return 0;
}

void add_door_test(struct node* elem, const struct door* new_door, int x) {
    add_door(elem, new_door);
    int count = 0;
    while (elem->next != NULL) {
        elem = elem->next;
        count++;
    }
    if (count == x)
        printf("SUCCESS\n");
    else
        printf("FAIL");
}

void remove_door_test(struct node* elem, struct node* root, int x) {
    remove_door(elem, root);
    int count = 0;
    while (elem->next != NULL) {
        elem = elem->next;
        count++;
    }
    if (count == x)
        printf("SUCCESS\n");
    else
        printf("FAIL");
}