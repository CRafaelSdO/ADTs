#include "libs/linked_list.h"

struct _linked_list {
	S64_t lngth;
	node_t *hd;
	node_t *tl;
};

linked_list_t *new_list() {
	linked_list_t *nw = (linked_list_t *) calloc(1, sizeof(linked_list_t));
	if(nw != NULL) {
		nw->lngth = 0;
		nw->hd = NULL;
		nw->tl = NULL;
	} else {
		printf("Erro:\n\tNão foi possível alocar memória para a nova lista.\n");
	}
	return nw;
}

void destroy_list(linked_list_t **lst, void (*destroy_item)(void **)) {
	if((*lst) != NULL) {
		destroy_node(&(*lst)->hd, destroy_item);
		free((*lst));
		(*lst) = NULL;
	}
}

void insert_by_item(void *itm, linked_list_t *lst, bool (*cmp)(void *, void *)) {
	if(lst != NULL) {
		node_t *nw = new_node(itm);
		node_t *tmp = lst->hd;
		if(cmp(itm, item(tmp))) {
			set_next(nw, lst->hd);
			lst->hd = nw;
			if(is_empty(lst)) {
				lst->tl = lst->hd;
			}
		} else {
			while(next(tmp) != NULL && !cmp(itm, item(tmp))) {
				tmp = next(tmp);
			}
			set_next(nw, next(tmp));
			set_next(tmp, nw);
		}
		lst->lngth++;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
	}
}

void insert_by_index(void *itm, S64_t ndx, linked_list_t *lst) {
	if(lst != NULL) {
		if(ndx == 0) {
			node_t *nw = new_node(itm);
			set_next(nw, lst->hd);
			lst->hd = nw;
			if(is_empty(lst)) {
				lst->tl = lst->hd;
			}
			lst->lngth++;
		} else if(ndx <= length(lst) && ndx > 0) {
			node_t *nw = new_node(itm);
			node_t *tmp = lst->hd;
			for(S64_t i = 0; i < ndx - 1; i++) {
				tmp = next(tmp);
			}
			set_next(nw, next(tmp));
			set_next(tmp, nw);
			lst->lngth++;
		} else {
			printf("Erro:\n\tIndice fora dos limítes.\n");
		}
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
	}
}

S64_t get_index_of_item(void *itm, linked_list_t *lst, bool (*eql)(void *, void *)) {
	if(lst != NULL) {
		node_t *tmp = lst->hd;
		S64_t ndx = 0;
		while(tmp != NULL) {
			if(eql(itm, item(tmp))) {
				return ndx;
			}
			ndx++;
			tmp = next(tmp);
		}
		return LLONG_MIN;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
		return LLONG_MIN;
	}
}

void *get_item_of_index(S64_t ndx, linked_list_t *lst) {
	if(lst != NULL) {
		if(ndx < 0 || ndx >= length(lst)) {
			printf("Erro:\n\tIndice fora dos limítes.\n");
			return NULL;
		}
		node_t *tmp = lst->hd;
		for(S64_t i = 0; i < ndx; i++) {
			tmp = next(tmp);
		}
		return item(tmp);
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
		return NULL;
	}
}

void *remove_by_item(void *itm, linked_list_t *lst, bool (*eql)(void *, void *)){
	if(lst != NULL) {
		node_t *tmp = lst->hd;
		while(next(tmp) != NULL) {
			if(eql(itm, item(next(tmp)))) {
				node_t *rmv = next(tmp);
				set_next(tmp, next(rmv));
				set_next(rmv, NULL);
				void *rtrn = item(rmv);
				set_item(rmv, NULL);
				destroy_node(&rmv, NULL);
				lst->lngth--;
				return rtrn;
			}
			tmp = next(tmp);
		}
		return NULL;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
		return NULL;
	}
}

void *remove_by_index(S64_t ndx, linked_list_t *lst) {
	if(lst != NULL) {
		if(ndx < 0 || ndx >= length(lst)) {
			printf("Erro:\n\tIndice fora dos limítes.\n");
			return NULL;
		}
		node_t *tmp = lst->hd;
		if(ndx == 0) {
			lst->hd = next(tmp);
			set_next(tmp, NULL);
			void *rtrn = item(tmp);
			set_item(tmp, NULL);
			destroy_node(&tmp, NULL);
			lst->lngth--;
			return rtrn;
		}
		for(S64_t i = 0; i < ndx - 1; i++) {
			tmp = next(tmp);
		}
		node_t *rmv = next(tmp);
		set_next(tmp, next(rmv));
		set_next(rmv, NULL);
		void *rtrn = item(rmv);
		set_item(rmv, NULL);
		destroy_node(&rmv, NULL);
		lst->lngth--;
		return rtrn;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
		return NULL;
	}
}

S64_t length(linked_list_t *lst) {
	if(lst != NULL) {
		return lst->lngth;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
		return LLONG_MIN;
	}
}

bool is_empty(linked_list_t *lst) {
	if(lst != NULL) {
		return length(lst) == 0;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
		return true;
	}
}