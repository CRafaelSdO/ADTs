//This Main is just for testing the codes
#include "DEBUG/debug.h"
#include "linked_list/libs/linked_list.h"

int main(int argc, char *argv[]) {
    linked_list_t *list = new_list(); DBG assert(0, length(list)) WTH PRNT "asserted list\n" ENDDBG
    for(int i = 0; i < 10; i++) {
        int *n = calloc(1, sizeof(int));
        (*n) = i;
        insert(n, 0, list); DBG assert(i + 1, length(list)) WTH PRNT "asserted list, %d\n", i ENDDBG
    }
}