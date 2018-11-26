#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <limits.h>
#include <stdbool.h>

typedef struct _linked_list LL_t;
typedef long long int S64_t;

LL_t *new_list();

void print_list(LL_t *, void (void *));

void destroy_list(LL_t **, void (void **));

void insert_by_item(void *, LL_t *, bool (void *, void *));

void insert_by_index(void *, S64_t, LL_t *);

S64_t get_index_of_item(void *, LL_t *, bool (void *, void *));

void *get_item_of_index(S64_t, LL_t *);

void *remove_by_item(void *, LL_t *, bool (void *, void *));

void *remove_by_index(S64_t, LL_t *);

S64_t length(LL_t *);

bool is_empty(LL_t *);

#endif