#ifndef LLN_H
#define LLN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _linked_list_node LLN_t;

LLN_t *new_node(void *);

void destroy_node(LLN_t **, void (void **));

void *item(LLN_t *);

void set_item(LLN_t *, void *);

LLN_t *next(LLN_t *);

void set_next(LLN_t *, LLN_t *);

#endif