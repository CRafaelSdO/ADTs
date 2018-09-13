#include "libs/node.h"

struct _node {
    void *item;
    node_t *next;
};

node_t *new_node(void *item) {
    node_t *new = (node_t *) calloc(1, sizeof(node_t));
    new->item = item;
    new->next = NULL;
    return new;
}

void destroy_node(node_t **node, void (*destroy_item)(void **)) {
    if((*node) != NULL) {
        destroy_node(&(*node)->next, destroy_item);
        destroy_item(&(*node)->item);
        free((*node));
        (*node) = NULL;
    }
}

void *item(node_t *node) {
    if(node != NULL) {
        return node->item;
    } else {
        return NULL;
    }
}

void set_item(node_t *node, void *item) {
    if(node != NULL) {
        node->item = item;
    }
}

node_t *next(node_t *node) {
    if(node != NULL) {
        return node->next;
    } else {
        return NULL;
    }
}

void set_next(node_t *node, node_t *next) {
    if(node != NULL) {
        node->next = next;
    }
}