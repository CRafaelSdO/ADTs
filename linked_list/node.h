#ifndef NODE_H

#include <stdbool.h>

#define NODE_H

typedef struct _node node_t;

node_t *new_node(void *);

void destroy_node(node_t **, void (void **));

void *get_item(node_t *);

node_t *get_next(node_t *);

void set_item(void *, node_t *);

void set_next(node_t *, node_t *);

#endif