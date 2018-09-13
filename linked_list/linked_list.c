    #include "libs/linked_list.h"

    struct _linked_list {
        U64_t length;
        node_t *head;
        node_t *tail;
    };

    linked_list_t *new_list() {
        linked_list_t *new = (linked_list_t *) calloc(1, sizeof(linked_list_t));
        new->length = 0;
        new->head = NULL;
        new->tail = NULL;
        return new;
    }

    void destroy_list(linked_list_t **list, void (*destroy_item)(void **)) {
        if((*list) != NULL) {
            destroy_node(&(*list)->head, destroy_item);
            free((*list));
            (*list) = NULL;
        }
    }

    void insert(void *item, U64_t index, linked_list_t *list) {
        if(list != NULL) {
            if(index == 0) {
                node_t *new = new_node(item);
                set_next(new, list->head);
                list->head = new;
                if(length(list) == 0) {
                    list->tail = list->head;
                }
            } else if(index <= length(list)){
                node_t *new = new_node(item);
                node_t *temp_node = list->head;
                for(U64_t i = 0; i < index - 1; i++) {
                    temp_node = next(temp_node);
                }
                set_next(new, next(temp_node));
                set_next(temp_node, new);
            } else {
                printf("Index out of bound!\n");
            }
        } else {
            printf("List is NULL!\n");
        }
    }

    void *remove_by_item(void *, linked_list_t *, bool (void *));

    void *remove_by_index(U64_t, linked_list_t *, bool (void *));

    U64_t length(linked_list_t *list) {
        if(list != NULL) {
            return list->length;
        } else {
            return 0;
        }
    }