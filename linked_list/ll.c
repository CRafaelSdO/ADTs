#include "libs/ll.h"

struct _linked_list {
	S64_t lngth;
	LLN_t *hd;
	LLN_t *tl;
};

LL_t *new_list() {
	LL_t *nw = (LL_t *) calloc(1, sizeof(LL_t));
	if(nw != NULL) {
		nw->lngth = 0;
		nw->hd = NULL;
		nw->tl = NULL;
		return nw;
	} else {
		printf("Erro (new_list):\n\tNão foi possível alocar memória para a nova lista.\n");
	}
	return NULL;
}

void print_list(LL_t *lst, void (prnt_itm)(void *)) {
	if(lst != NULL) {
		if(prnt_itm != NULL) {
			LLN_t *tmp = lst->hd;
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

void destroy_list(LL_t **lst, void (*destroy_item)(void **)) {
	if((*lst) != NULL) {
		destroy_node(&(*lst)->hd, destroy_item);
		free((*lst));
		(*lst) = NULL;
	} else {
		printf("Erro (destroy_list):\n\tO ponteiro para a lista é NULL.\n");
	}
}

void insert_by_item(void *itm, LL_t *lst, bool (*cmp)(void *, void *)) {
	if(lst != NULL) {
		if(cmp != NULL) {
			LLN_t *nw = new_node(itm);
			LLN_t *tmp = lst->hd;
			if(is_empty(lst)) {
				set_next(nw, lst->hd);
				lst->hd = nw;
				lst->tl = lst->hd;
			} else if(cmp(itm, item(tmp))) {
				set_next(nw, lst->hd);
				lst->hd = nw;
			} else {
				while(next(tmp) != NULL && !cmp(itm, item(tmp))) {
					tmp = next(tmp);
				}
				set_next(nw, next(tmp));
				set_next(tmp, nw);
			}
			lst->lngth++;
		} else {
			printf("Erro (insert_by_item):\n\tO ponteiro para a função é NULL.\n");
		}
	} else {
		printf("Erro (insert_by_item):\n\tO ponteiro para a lista é NULL.\n");
	}
}

void insert_by_index(void *itm, S64_t ndx, LL_t *lst) {
	if(lst != NULL) {
		if(ndx == 0) {
			LLN_t *nw = new_node(itm);
			set_next(nw, lst->hd);
			lst->hd = nw;
			if(is_empty(lst)) {
				lst->tl = lst->hd;
			}
			lst->lngth++;
		} else if(ndx <= length(lst) && ndx > 0) {
			LLN_t *nw = new_node(itm);
			LLN_t *tmp = lst->hd;
			for(S64_t i = 0; i < ndx - 1; i++) {
				tmp = next(tmp);
			}
			set_next(nw, next(tmp));
			set_next(tmp, nw);
			lst->lngth++;
		} else {
			printf("Erro (insert_by_index):\n\tIndice fora dos limítes.\n");
		}
	} else {
		printf("Erro (insert_by_index):\n\tO ponteiro para a lista é NULL.\n");
	}
}

S64_t get_index_of_item(void *itm, LL_t *lst, bool (*eql)(void *, void *)) {
	if(lst != NULL) {
		if(eql != NULL) {
			LLN_t *tmp = lst->hd;
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

void *get_item_of_index(S64_t ndx, LL_t *lst) {
	if(lst != NULL) {
		if(ndx < 0 || ndx >= length(lst)) {
			printf("Erro (get_item_of_index):\n\tIndice fora dos limítes.\n");
		} else {
			LLN_t *tmp = lst->hd;
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

void *remove_by_item(void *itm, LL_t *lst, bool (*eql)(void *, void *)){
	if(lst != NULL) {
		if(eql != NULL) {
			LLN_t *tmp = lst->hd;
			while(next(tmp) != NULL) {
				if(eql(itm, item(next(tmp)))) {
					LLN_t *rmv = next(tmp);
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
		} else {
			printf("Erro (remove_by_item):\n\tO ponteiro para a função é NULL.\n");
		}
	} else {
		printf("Erro (remove_by_item):\n\tO ponteiro para a lista é NULL.\n");
	}
	return NULL;
}

void *remove_by_index(S64_t ndx, LL_t *lst) {
	if(lst != NULL) {
		if(ndx < 0 || ndx >= length(lst)) {
			printf("Erro:\n\tIndice fora dos limítes.\n");
		} else {
			LLN_t *tmp = lst->hd;
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
			LLN_t *rmv = next(tmp);
			set_next(tmp, next(rmv));
			set_next(rmv, NULL);
			void *rtrn = item(rmv);
			set_item(rmv, NULL);
			destroy_node(&rmv, NULL);
			lst->lngth--;
			return rtrn;
		}
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
	}
	return NULL;
}

S64_t length(LL_t *lst) {
	if(lst != NULL) {
		return lst->lngth;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
	}
	return LLONG_MIN;
}

bool is_empty(LL_t *lst) {
	if(lst != NULL) {
		return length(lst) == 0;
	} else {
		printf("Erro:\n\tO ponteiro para a lista é NULL.\n");
	}
	return true;
}