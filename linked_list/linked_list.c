#include "linked_list.h"

struct _linked_list {
    long int size;
    node_t *head;
    node_t *tail;
};

linked_list_t *new_list() {
    linked_list_t *new = (linked_list_t *) calloc(1, sizeof(linked_list_t));
    new->size = 0;
    new->head = NULL;
    new->tail = NULL;
}

void destroy_list(linked_list_t **list, void (*destroy_item)(void **)) {
    if((*list) != NULL) {
        destroy_node(&list->head, destroy_item);
        free((*list));
        (*list) = NULL;
    }
}

void push(void *, linked_list_t *);

void *pop(void *, linked_list_t *, bool (void *));