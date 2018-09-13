#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct _linked_list linked_list_t;
typedef unsigned long int U64_t;

linked_list_t *new_list();

void destroy_list(linked_list_t **, void (void **));

void insert(void *, U64_t, linked_list_t *);

void *get();

void *remove_by_item(void *, linked_list_t *, bool (void *));

void *remove_by_index(U64_t, linked_list_t *, bool (void *));

U64_t length(linked_list_t *list);

#endif