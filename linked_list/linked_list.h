#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _linked_list linked_list_t;

linked_list_t *new_list();

void destroy_list(linked_list_t **, void (void **));

void push(void *, linked_list_t *);

void *pop(void *, linked_list_t *, bool (void *));

#endif