//This Main is just for testing the codes
#include "double_linked_list/libs/dll.h"

bool equals_int(void *x, void *y) {
    if(x != NULL && y != NULL) {
        return (*((int *) x)) == (*((int *) y));
    } else {
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

void print_int(void *n) {
    printf("%d\n", (*((int *) n)));
}

void destroy_int(void **n) {
    free((*n));
    (*n) = NULL;
}

int main(int argc, char *argv[]) {
    DLL_t *oList = new_list();
    DLL_t *uList = new_list();

    if(is_empty(oList)) printf("oList vazia\n"); else  printf("oList não vazia\n");
    printf("Tamanho da oList:\t%lld\n", length(oList));
    printf("oList:\n");
    print_list(oList, print_int);
    
    printf("\n");

    if(is_empty(uList)) printf("uList vazia\n"); else printf("uList não vazia\n");
    printf("Tamanho da uList:\t%lld\n", length(uList));
    printf("\nuList:\n");
    print_list(uList, print_int);

    printf("\n");

    int *aux = NULL;
    for(int i = 0; i <= 10; i++) {
        aux = (int *) calloc(1, sizeof(int));
        (*aux) = i;
        insert_by_item(aux, oList, compare_int);
        printf("%d adicionado na oList\n", i);
        insert_by_index(aux, 0, uList);
        printf("%d adicionado na uList\n", i);
    }

    printf("\n");

    if(is_empty(oList)) printf("oList vazia\n"); else  printf("oList não vazia\n");
    printf("Tamanho da oList:\t%lld\n", length(oList));
    printf("oList:\n");
    print_list(oList, print_int);
    
    printf("\n");

    if(is_empty(uList)) printf("uList vazia\n"); else printf("uList não vazia\n");
    printf("Tamanho da uList:\t%lld\n", length(uList));
    printf("uList:\n");
    print_list(uList, print_int);

    printf("\n");

    printf("Cara do indíce 2:\n");
    printf("Na oList:\t");
    print_int(get_item_of_index(2, oList));
    printf("Na uList:\t");
    print_int(get_item_of_index(2, uList));

    printf("\n");

    aux = (int *) calloc(1, sizeof(int));
    (*aux) = 2;

    printf("Indíce do 2:\n");
    printf("Na oList:\t%lld\n", get_index_of_item(aux, oList, equals_int));
    printf("Na uList:\t%lld\n", get_index_of_item(aux, uList, equals_int));

    printf("\n");

    printf("Removendo do indíce 5:\n");
    remove_by_index(5, oList);
    remove_by_index(5, uList);

    printf("\n");

    if(is_empty(oList)) printf("oList vazia\n"); else  printf("oList não vazia\n");
    printf("Tamanho da oList:\t%lld\n", length(oList));
    printf("oList:\n");
    print_list(oList, print_int);
    
    printf("\n");

    if(is_empty(uList)) printf("uList vazia\n"); else printf("uList não vazia\n");
    printf("Tamanho da uList:\t%lld\n", length(uList));
    printf("uList:\n");
    print_list(uList, print_int);

    printf("\n");

    printf("Removendo o 2:\n");
    remove_by_item(aux, oList, equals_int);
    remove_by_item(aux, uList, equals_int);

    printf("\n");

    if(is_empty(oList)) printf("oList vazia\n"); else  printf("oList não vazia\n");
    printf("Tamanho da oList:\t%lld\n", length(oList));
    printf("oList:\n");
    print_list(oList, print_int);
    
    printf("\n");

    if(is_empty(uList)) printf("uList vazia\n"); else printf("uList não vazia\n");
    printf("Tamanho da uList:\t%lld\n", length(uList));
    printf("uList:\n");
    print_list(uList, print_int);

    printf("\n");

    destroy_list(&oList, destroy_int);
    if(oList == NULL) printf("oList destruida\n");
    destroy_list(&uList, destroy_int);
    if(uList == NULL) printf("uList destruida\n");

    return 0;
}