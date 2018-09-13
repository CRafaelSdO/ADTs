#include "node.h"

struct _node {
    void *item;
    node_t *next;
};

node_t *new_node(void *item) {
    node_t *new = (node_t *) calloc(1, sizeof(node_t));
    new->item = item;
    new->next = NULL;
}

void destroy_node(node_t **node, void (*destroy_item)(void **)) {
    if((*node) != NULL) {
        destroy_node(&(*node)->next);
        destroy_item(&(*node)->item);
        free((*node));
        (*node) = NULL;
    }
}

void *get_item(node_t *node) {
    if(node != NULL) {
        return node->item;
    }
}

node_t *get_next(node_t *node) {
    if(node != NULL) {
        return node->next;
    }
}

void set_item(void *item, node_t *node) {
    if(node != NULL) {
        node->item = item;
    }
}

void set_next(node_t *next, node_t *node) {
    if(node != NULL) {
        node->next = next;
    }
}