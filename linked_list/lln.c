#include "libs/lln.h"

struct _linked_list_node {
	void *itm;
	LLN_t *nxt;
};

LLN_t *new_node(void *itm) {
	LLN_t *nw = (LLN_t *) calloc(1, sizeof(LLN_t));
	if(nw != NULL) {
		nw->itm = itm;
		nw->nxt = NULL;
	} else {
		printf("Erro (new_node):\n\tNão foi possível alocar memória para o novo node.\n");
	}
	return nw;
}

void destroy_node(LLN_t **nd, void (*destroy_item)(void **)) {
	if((*nd) != NULL) {
		if((*nd)->nxt != NULL) {
			destroy_node(&(*nd)->nxt, destroy_item);
		}
		if(destroy_item != NULL) {
			destroy_item(&(*nd)->itm);
		}
		free((*nd));
		(*nd) = NULL;
	} else {
		printf("Erro (destroy_node):\n\tO ponteiro para o node é NULL.\n");
	}
}

void *item(LLN_t *nd) {
	if(nd != NULL) {
		return nd->itm;
	} else {
		printf("Erro (item):\n\tO ponteiro para o node é NULL.\n");
	}
	return NULL;
}

void set_item(LLN_t *nd, void *itm) {
	if(nd != NULL) {
		nd->itm = itm;
	} else {
		printf("Erro (set_item):\n\tO ponteiro para o node é NULL.\n");
	}
}

LLN_t *next(LLN_t *nd) {
	if(nd != NULL) {
		return nd->nxt;
	} else {
		printf("Erro (next):\n\tO ponteiro para o node é NULL.\n");
	}
	return NULL;
}

void set_next(LLN_t *nd, LLN_t *nxt) {
	if(nd != NULL) {
		nd->nxt = nxt;
	} else {
		printf("Erro (set_next):\n\tO ponteiro para o node é NULL.\n");
	}
}