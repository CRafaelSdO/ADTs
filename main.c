//This Main is just for testing the codes
#include "DEBUG/debug.h"
#include "linked_list/libs/linked_list.h"

bool equals_int(void *x, void *y) {
    if(x != NULL && y != NULL) {
        return (*((int *) x)) == (*((int *) y));
    } else if(x == NULL || y != NULL) {
        return false;
    }
}

bool compare_int(void *x, void *y) {
    if(x != NULL && y != NULL) {
        return (*((int *) x)) < (*((int *) y));
    } else if(x != NULL) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    linked_list_t *list = new_list(); DBG assert(0, length(list)) WTH PRNT "asserted list\n" ENDDBG
    for(int i = 0; i < 3; i++) {
        int *n = (int *) calloc(1, sizeof(int));
        (*n) = 0;
        insert((void *) n, 0, list); DBG assert(i + 1, length(list)) WTH PRNT "asserted list, %d\n", i ENDDBG
    }
    int *n = (int *) calloc(1, sizeof(int));
    (*n) = 1;
    insert((void *) n, 1, list);
    DBG assert(1, get_index_of_item((void *) n, list, equals_int)) WTH PRNT "asserted 1\n" ENDDBG
    DBG assert(2, get_index_of_item((void *) n, list, equals_int)) WTH PRNT "asserted 2\n" ENDDBG
    printf("%lld\n", get_index_of_item((void *) n, list, equals_int));
}