#include "libs/dll.h"

struct _double_linked_list {
	S64_t lngth;
	DLLN_t *hd;
	DLLN_t *tl;
};

DLL_t *new_list() {
	DLL_t *nw = (DLL_t *) calloc(1, sizeof(DLL_t));
	if(nw != NULL) {
		nw->lngth = 0;
		nw->hd = NULL;
		nw->tl = NULL;
	} else {
		printf("Erro (new_list):\n\tNão foi possível alocar memória para a nova lista.\n");
	}
	return nw;
}

void print_list(DLL_t *lst, void (prnt_itm)(void *)) {
	if(lst != NULL) {
		if(prnt_itm != NULL) {
			DLLN_t *tmp = lst->hd;
			for(S64_t i = 0; i < length(lst); i++) {
				printf("|%lld|\n", i);
				prnt_itm(item(tmp));
				tmp = next(tmp);
			}
		} else {
			printf("Erro (print_list):\n\tO ponteiro para a função é NULL.\n");
		}
	} else {
		printf("Erro (print_list):\n\tO ponteiro para a lista é NULL.\n");
	}
}

void destroy_list(DLL_t **lst, void (*destroy_item)(void **)) {
	if((*lst) != NULL) {
		destroy_node(&(*lst)->hd, destroy_item);
		free((*lst));
		(*lst) = NULL;
	} else {
		printf("Erro (destroy_list):\n\tO ponteiro para a lista é NULL.\n");
	}
}

void insert_by_item(void *itm, DLL_t *lst, bool (*cmp)(void *, void *)) {
	if(lst != NULL) {
		if(cmp != NULL) {
			DLLN_t *nw = new_node(itm);
			DLLN_t *tmp = lst->hd;
			if(is_empty(lst)) {
				lst->hd = nw;
				lst->tl = lst->hd;
			} else if(cmp(itm, item(tmp))) {
				set_next(nw, tmp);
				set_previus(tmp, nw);
				lst->hd = nw;
			} else {
				while(tmp != NULL && !cmp(itm, item(tmp))) {
					tmp = next(tmp);
				}
				if(tmp != NULL) {
					set_next(nw, tmp);
					set_previus(nw, previus(tmp));
					set_next(previus(tmp), nw);
					set_previus(tmp, nw);
				} else {
					set_next(lst->tl, nw);
					set_previus(nw, lst->tl);
					lst->tl = nw;
				}
			}
			lst->lngth++;
		} else {
			printf("Erro (insert_by_item):\n\tO ponteiro para a função é NULL.\n");
		}
	} else {
		printf("Erro (insert_by_item):\n\tO ponteiro para a lista é NULL.\n");
	}
}

void insert_by_index(void *itm, S64_t ndx, DLL_t *lst) {
	if(lst != NULL) {
		if(ndx == 0) {
			DLLN_t *nw = new_node(itm);
			set_next(nw, lst->hd);
			lst->hd = nw;
			if(is_empty(lst)) {
				lst->tl = lst->hd;
			}
			lst->lngth++;
		} else if(ndx > 0 && ndx < length(lst)) {
			DLLN_t *nw = new_node(itm);
			DLLN_t *tmp = lst->hd;
			for(S64_t i = 0; i < ndx; i++) {
				tmp = next(tmp);
			}
			set_next(nw, tmp);
			set_previus(nw, previus(tmp));
			set_next(previus(tmp), nw);
			set_previus(tmp, nw);
			lst->lngth++;
		} else if(ndx == length(lst)) {
			DLLN_t *nw = new_node(itm);
			set_next(lst->tl, nw);
			set_previus(nw, lst->tl);
			lst->tl = nw;
			lst->lngth++;
		} else {
			printf("Erro (insert_by_index):\n\tIndice fora dos limítes.\n");
		}
	} else {
		printf("Erro (insert_by_index):\n\tO ponteiro para a lista é NULL.\n");
	}
}

S64_t get_index_of_item(void *itm, DLL_t *lst, bool (*eql)(void *, void *)) {
	if(lst != NULL) {
		if(eql != NULL) {
			DLLN_t *tmp = lst->hd;
			S64_t ndx = 0;
			while(tmp != NULL) {
				if(eql(itm, item(tmp))) {
					return ndx;
				}
				ndx++;
				tmp = next(tmp);
			}
		} else {
			printf("Erro (get_index_of_item):\n\tO ponteiro para a função é NULL.\n");
		}
	} else {
		printf("Erro (get_index_of_item):\n\tO ponteiro para a lista é NULL.\n");
	}
	return LLONG_MIN;
}

void *get_item_of_index(S64_t ndx, DLL_t *lst) {
	if(lst != NULL) {
		if(ndx < 0 || ndx >= length(lst)) {
			printf("Erro (get_item_of_index):\n\tIndice fora dos limítes.\n");
		} else {
			DLLN_t *tmp = lst->hd;
			for(S64_t i = 0; i < ndx; i++) {
				tmp = next(tmp);
			}
			return item(tmp);
		}
	} else {
		printf("Erro (get_item_of_index):\n\tO ponteiro para a lista é NULL.\n");
	}
	return NULL;
}

void *remove_node(DLLN_t *rmv, DLL_t *lst) {
	if(rmv != lst->hd) {
		set_next(previus(rmv), next(rmv));
	} else {
		lst->hd = next(rmv);
	}
	if(rmv != lst->tl) {
		set_previus(next(rmv), previus(rmv));
	} else {
		lst->tl = previus(rmv);
	}
	void *rtrn = item(rmv);
	set_next(rmv, NULL);
	set_previus(rmv, NULL);
	set_item(rmv, NULL);
	destroy_node(&rmv, NULL);
	lst->lngth--;
	return rtrn;
}

void *remove_by_item(void *itm, DLL_t *lst, bool (*eql)(void *, void *)){
	if(lst != NULL) {
		if(eql != NULL) {
			DLLN_t *rmv = lst->hd;
			if(is_empty(lst)) {
				printf("Erro (remove_by_item):\n\tLista vazia.\n");
			} else {
				while(rmv != NULL) {
					if(eql(itm, item(rmv))) {
						return remove_node(rmv, lst);
					}
					rmv = next(rmv);
				}
			}
		} else {
			printf("Erro (remove_by_item):\n\tO ponteiro para a função é NULL.\n");
		}
	} else {
		printf("Erro (remove_by_item):\n\tO ponteiro para a lista é NULL.\n");
	}
	return NULL;
}

void *remove_by_index(S64_t ndx, DLL_t *lst) {
	if(lst != NULL) {
		if(ndx < 0 || ndx >= length(lst)) {
			printf("Erro (remove_by_index):\n\tIndice fora dos limítes.\n");
		} else {
			DLLN_t *rmv = lst->hd;
			for(S64_t i = 0; i < ndx; i++) {
				rmv = next(rmv);
			}
			return remove_node(rmv, lst);
		}
	} else {
		printf("Erro (remove_by_index):\n\tO ponteiro para a lista é NULL.\n");
	}
	return NULL;
}

S64_t length(DLL_t *lst) {
	if(lst != NULL) {
		return lst->lngth;
	} else {
		printf("Erro (length):\n\tO ponteiro para a lista é NULL.\n");
	}
	return LLONG_MIN;
}

bool is_empty(DLL_t *lst) {
	if(lst != NULL) {
		return length(lst) == 0;
	} else {
		printf("Erro (is_empty):\n\tO ponteiro para a lista é NULL.\n");
	}
	return true;
}