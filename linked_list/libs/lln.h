#ifndef LLN_H
#define LLN_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Definição do tipo LLN_t por conveniência.
 */
typedef struct _linked_list_node LLN_t;

/*
 * Te dá o ponteiro para um novo node.
 * Argumentos:
 * 1. Ponteiro (void *) para o item do o novo node.
 * Retorno:
 * - Ponteiro (LLN_t *) para o novo node.
 * - NULL caso não seja possível alocar memória para o novo ponteiro.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
LLN_t *new_node(void *);

/*
 * Destrói (libera a memória usada) uma sequência de nodes e
 * seta o ponteiro para o primeiro node para NULL.
 * Argumentos:
 * 1. Ponteiro para o ponteiro (LLN_t **) para o primeiro node da sequência.
 * 2. Ponteiro para função (void) que destrói os itens.
 *   Argumentos:
 *   1. Ponteiro para o ponteiro (void **) para o item a ser destruido.
 * OBS: Não faz nada e imprime uma mensagem de erro
 * caso o ponteiro para o primeiro node da sequência (1) seja NULL.
 */
void destroy_node(LLN_t **, void (void **));

/*
 * Te dá o ponteiro para o item de determinado node.
 * Argumentos:
 * 1. Ponteiro (LLN_t *) para o node de que se deseja o item.
 * Retorno:
 * - Ponteiro (void *) para o item do node (1).
 * - NULL caso o ponteiro para o node (1) seja NULL.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
void *item(LLN_t *);

/*
 * Seta o ponteiro para o item de determinado node.
 * Argumentos:
 * 1. Ponteiro (LLN_t *) para o node de que se deseja mudar o item.
 * 2. Ponteiro (void *) para o novo item.
 * OBS: Não faz nada e imprime uma mensagem de erro caso o ponteiro para o node (1) seja NULL.
 */
void set_item(LLN_t *, void *);

/*
 * Te dá o ponteiro para o node seguinte de determinado node.
 * Argumentos:
 * 1. Ponteiro (LLN_t *) para o node de que se deseja o ponteiro para o node seguinte.
 * Retorno:
 * - Ponteiro (LLN_t *) para o node seguinte.
 * - NULL caso o ponteiro para o node (1) seja NULL.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
LLN_t *next(LLN_t *);

/*
 * Seta o ponteiro para o node seguinte de determinado node.
 * Argumentos:
 * 1. Ponteiro (LLN_t *) para o node de que se deseja mudar o ponteiro para o node seguinte.
 * 2. Ponteiro (LLN_t *) para o novo node seguinte.
 * OBS: Não faz nada e imprime uma mensagem de erro caso o ponteiro para o node (1) seja NULL.
 */
void set_next(LLN_t *, LLN_t *);

#endif