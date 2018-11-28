#ifndef DLL_H
#define DLL_H

#include "dlln.h"
#include <limits.h>
#include <stdbool.h>

/*
 * Definição dos tipos DLL_t e S64 por conveniência.
 */
typedef struct _double_linked_list DLL_t;
typedef long long int S64_t;

/*
 * Te dá o ponteiro para uma nova lista.
 * Retorno:
 * - Ponteiro (DLL_t *) para a nova lista.
 * - NULL caso não seja possível alocar memória para a nova lista.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
DLL_t *new_list();

/*
 * Imprime uma lista.
 * OBS: algumas mudaças são nescessárias caso o promt não seja a saida desejada.
 * Argumentos:
 * 1. Ponteiro (DLL_t *) para a lista a ser impressa.
 * 2. Ponteiro para função (void) que imprime os itens.
 *   Argumentos:
 *   1. Ponteiro (void *) do item a ser impresso.
 * OBS: Não faz nada e imprime uma mensagem de erro
 * caso o ponteiro para a lista (1) seja NULL ou
 * caso o ponteiro para a função (2) seja NULL;
 */
void print_list(DLL_t *, void (void *));

/*
 * Destroi (libera a memória usada) uma lista e seta o ponteiro para NULL.
 * Argumentos:
 * 1. Ponteiro para o ponteiro (DLL_t **) para a lista a ser destruida.
 * 2. Ponteiro para função (void) que destrói os itens.
 *   Argumentos:
 *   1. Ponteiro para o ponteiro (void **) do item a ser destruido.
 * OBS: Não faz nada e imprime uma mensagem de erro
 * caso o ponteiro para a lista (1) seja NULL.
 */
void destroy_list(DLL_t **, void (void **));

/*
 * Adiciona um item de forma ordenada em uma lista.
 * Argumentos:
 * 1. Ponteiro (void *) do item a ser adicionado.
 * 2. Ponteiro (DLL_t *) para a lista na qual o item sera adicionado.
 * 3. Ponteiro para função (bool) que compara os itens.
 *   Argumentos:
 *   1. Ponteiro (void *) do primeiro item.
 *   2. Ponteiro (void *) do segundo item.
 *   Retorno:
 *   - True, caso o primeiro item venha antes do segundo item.
 *   - False, em qualquer outro caso.
 * OBS: Não faz nada e imprime uma mensagem de erro
 * caso o ponteiro para a lista (2) seja NULL ou
 * caso o ponteiro para a função (3) seja NULL;
 */
void insert_by_item(void *, DLL_t *, bool (void *, void *));

/*
 * Adiciona um item em uma lista no indíce desejado.
 * Argumentos:
 * 1. Ponteiro (void *) do item a ser adicionado.
 * 2. Indíce (S64_t) onde se deseja adicionar o item.
 * 3. Ponteiro (DLL_t *) para a lista na qual o item sera adicionado.
 * OBS: Não faz nada se o indíce (2) for menor que 0 ou
 * se o indíce (2) for maior que o tamanho atual da lista ou
 * caso o ponteiro para a lista (1) seja NULL
 * e imprime uma mensagen de erro nesses casos.
 */
void insert_by_index(void *, S64_t, DLL_t *);

/*
 * Te dá o indíce de determinado item.
 * Argumentos:
 * 1. Ponteiro (void *) de um item identico ao de que se deseja o indíce.
 * 2. Ponteiro (DLL_t *) para a lista onde se deseja procurar.
 * 3. Ponteiro para função (bool) que compara os itens.
 *   Argumentos:
 *   1. Ponteiro (void *) do primeiro item.
 *   2. Ponteiro (void *) do segundo item.
 *   Retorno:
 *   - True, caso o primeiro item seja igual ao segundo item.
 *   - False, em qualquer outro caso.
 * Retorno:
 * - Indíce (S64_t) do item (1) caso ele sejá encontrado na lista.
 * - LLONG_MIN caso o item (1) não seja encontrado na lista (2).
 * - LLONG_MIN caso o ponteiro para a lista (2) seja NULL.
 * - LLONG_MIN caso o ponteiro para a função (3) seja NULL.
 * OBS: Imprime uma mensagem de erro nestes dois últimos casos.
 */
S64_t get_index_of_item(void *, DLL_t *, bool (void *, void *));

/*
 * Te dá o ponteiro do item que está em determinado indíce.
 * Argumentos:
 * 1. Indíce (S64_t) do qual se deseja o item.
 * 2. Ponteiro (DLL_t *) para a lista de que se deseja o item.
 * Retorno:
 * - Ponteiro (void *) do item que está no indíce (1) desejado.
 * - NULL caso o indíce (1) seja menor que 0 ou maior ou igual ao tamanho atual da lista.
 * - NULL caso o ponteiro para a lista (2) seja NULL.
 * OBS: Imprime uma mensagem de erro nos dois últimos casos.
 */
void *get_item_of_index(S64_t, DLL_t *);

/*
 * Remove determinado item de uma lista e te dá o ponteiro dele.
 * Argumentos:
 * 1. Ponteiro (void *) de um item identico ao que se deseja remover.
 * 2. Ponteiro (DLL_t *) para a lista de onde se deseja remover.
 * 3. Ponteir para função (bool) que compara os itens.
 *   Argumentos:
 *   1. Ponteiro (void *) do primeiro item.
 *   2. Ponteiro (void *) do segundo item.
 *   Retorno:
 *   - True, caso o primeiro item seja igual ao segundo item.
 *   - False, em qualquer outro caso.
 * Retorno:
 * - Ponteiro (void *) do item (1) que foi removido.
 * - NULL caso o item (1) não sejá encontrado na lista (2).
 * - NULL caso o ponteiro para a lista (2) seja NULL.
 * - NULL caso o ponteiro para a função (3) seja NULL.
 */
void *remove_by_item(void *, DLL_t *, bool (void *, void *));

/*
 * Remove o item de determinado indíce de uma lista e te dá o ponteiro dele.
 * Argumentos:
 * 1. Indíce (S64_t) do qual se deseja remover.
 * 2. Ponteiro (DLL_t *) para a lista de que se deseja remover.
 * Retorno:
 * - Ponteiro (void *) do item que estava no indíce (1) e que foi removido.
 * - NULL caso o indíce (1) seja menor que 0 ou maior ou igual ao tamanho atual da lista.
 * - NULL caso o ponteiro para a lista (2) seja NULL.
 * OBS: Imprime uma mensagem de erro nos dois últimos casos.
 */
void *remove_by_index(S64_t, DLL_t *);

/*
 * Te dá do tamanho (quantidade de itens) de uma lista.
 * Argumentos:
 * 1. Ponteiro (DLL_t *) para a lista de qual se deseja o tamanho.
 * Retorno:
 * - Tamanho (S64_t) da lista (1).
 * - LLONG_MIN caso o ponteiro para a lista (1) seja NULL.
 * OBS: Imprime uma mensagem de erro nesto último caso.
 */
S64_t length(DLL_t *);

/*
 * Te diz se uma lista está vazia.
 * Argumentos:
 * 1. Ponteiro (DLL_t *) para a lista que se deseja saber se está vazia.
 * Retorno:
 * - True se a lista está vazia.
 * - False se a lista não está vazia.
 * - True caso o ponteiro para a lista (1) seja NULL.
 * OBS: Imprime uma mensagem de erro nesto último caso.
 */
bool is_empty(DLL_t *);

#endif