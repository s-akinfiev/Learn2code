#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node* init(const struct door* door) {
    struct node* head = malloc(sizeof(struct node));
    head->door = *door;
    head->next = NULL;
    return head;
}

struct node* add_door(struct node* elem, const struct door* new_door) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->door = *new_door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* p = root; 
    while (p != NULL && p->door.id != door_id)
        p = p->next;
    return p;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (root == NULL || elem == NULL) return NULL;
    
    struct node* target = find_door(elem->door.id, root);
    if (target == NULL) return NULL;

    if (root == target) {
        root = target->next;
    } else {
        struct node* parrent = root;
        while (parrent != NULL && parrent->next != target)
            parrent = parrent->next;
        
        if (parrent != NULL)
            parrent->next = target->next;
    }
    
    free(target);
    return root;


}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* tmp = root;
        root = root->next;
        free(tmp);
    }
}