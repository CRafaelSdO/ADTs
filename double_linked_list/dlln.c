#include "libs/dlln.h"

struct _double_linked_list_node {
	void *itm;
	DLLN_t *nxt;
	DLLN_t *prv;
};

DLLN_t *new_node(void *itm) {
	DLLN_t *nw = (DLLN_t *) calloc(1, sizeof(DLLN_t));
	if(nw != NULL) {
		nw->itm = itm;
		nw->nxt = NULL;
		nw->prv = NULL;
		return nw;
	} else {
		printf("Erro (new_node):\n\tNão foi possível alocar memória para o novo node.\n");
	}
	return NULL;
}

void destroy_node(DLLN_t **nd, void (*destroy_item)(void **)) {
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

void *item(DLLN_t *nd) {
	if(nd != NULL) {
		return nd->itm;
	} else {
		printf("Erro (item):\n\tO ponteiro para o node é NULL.\n");
	}
	return NULL;
}

void set_item(DLLN_t *nd, void *itm) {
	if(nd != NULL) {
		nd->itm = itm;
	} else {
		printf("Erro (set_item):\n\tO ponteiro para o node é NULL.\n");
	}
}

DLLN_t *next(DLLN_t *nd) {
	if(nd != NULL) {
		return nd->nxt;
	} else {
		printf("Erro (next):\n\tO ponteiro para o node é NULL.\n");
	}
	return NULL;
}

void set_next(DLLN_t *nd, DLLN_t *nxt) {
	if(nd != NULL) {
		nd->nxt = nxt;
	} else {
		printf("Erro (set_next):\n\tO ponteiro para o node é NULL.\n");
	}
}

DLLN_t *previus(DLLN_t *nd) {
	if(nd != NULL) {
		return nd->prv;
	} else {
		printf("Erro (next):\n\tO ponteiro para o node é NULL.\n");
	}
	return NULL;
}

void set_previus(DLLN_t *nd, DLLN_t *prv) {
	if(nd != NULL) {
		nd->prv = prv;
	} else {
		printf("Erro (set_next):\n\tO ponteiro para o node é NULL.\n");
	}
}