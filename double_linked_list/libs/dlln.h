#ifndef DLLN_H
#define DLLN_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Definição do tipo DLLN_t por conveniência.
 */
typedef struct _double_linked_list_node DLLN_t;

/*
 * Te dá o ponteiro para um novo node.
 * Argumentos:
 * 1. Ponteiro (void *) para o item do o novo node.
 * Retorno:
 * - Ponteiro (DLLN_t *) para o novo node.
 * - NULL caso não seja possível alocar memória para o novo ponteiro.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
DLLN_t *new_node(void *);

/*
 * Destrói (libera a memória usada) uma sequência de nodes e
 * seta o ponteiro para o primeiro node para NULL.
 * Argumentos:
 * 1. Ponteiro para o ponteiro (DLLN_t **) para o primeiro node da sequência.
 * 2. Ponteiro para função (void) que destrói os itens.
 *   Argumentos:
 *   1. Ponteiro para o ponteiro (void **) para o item a ser destruido.
 * OBS: Não faz nada e imprime uma mensagem de erro
 * caso o ponteiro para o primeiro node da sequência (1) seja NULL.
 */
void destroy_node(DLLN_t **, void (void **));

/*
 * Te dá o ponteiro para o item de determinado node.
 * Argumentos:
 * 1. Ponteiro (DLLN_t *) para o node de que se deseja o item.
 * Retorno:
 * - Ponteiro (void *) para o item do node (1).
 * - NULL caso o ponteiro para o node (1) seja NULL.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
void *item(DLLN_t *);

/*
 * Seta o ponteiro para o item de determinado node.
 * Argumentos:
 * 1. Ponteiro (DLLN_t *) para o node de que se deseja mudar o item.
 * 2. Ponteiro (void *) para o novo item.
 * OBS: Não faz nada e imprime uma mensagem de erro caso o ponteiro para o node (1) seja NULL.
 */
void set_item(DLLN_t *, void *);

/*
 * Te dá o ponteiro para o node seguinte à determinado node.
 * Argumentos:
 * 1. Ponteiro (DLLN_t *) para o node de que se deseja o ponteiro para o node seguinte.
 * Retorno:
 * - Ponteiro (DLLN_t *) para o node seguinte.
 * - NULL caso o ponteiro para o node (1) seja NULL.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
DLLN_t *next(DLLN_t *);

/*
 * Seta o ponteiro para o node seguinte à determinado node.
 * Argumentos:
 * 1. Ponteiro (DLLN_t *) para o node de que se deseja mudar o ponteiro para o node seguinte.
 * 2. Ponteiro (DLLN_t *) para o novo node seguinte.
 * OBS: Não faz nada e imprime uma mensagem de erro caso o ponteiro para o node (1) seja NULL.
 */
void set_next(DLLN_t *, DLLN_t *);

/*
 * Te dá o ponteiro para o node anterior à determinado node.
 * Argumentos:
 * 1. Ponteiro (DLLN_t *) para o node de que se deseja o ponteiro para o node anterior.
 * Retorno:
 * - Ponteiro (DLLN_t *) para o node anterior.
 * - NULL caso o ponteiro para o node (1) seja NULL.
 * OBS: Imprime uma mensagem de erro neste último caso.
 */
DLLN_t *previus(DLLN_t *);

/*
 * Seta o ponteiro para o node anterior à determinado node.
 * Argumentos:
 * 1. Ponteiro (DLLN_t *) para o node de que se deseja mudar o ponteiro para o node anterior.
 * 2. Ponteiro (DLLN_t *) para o novo node anterior.
 * OBS: Não faz nada e imprime uma mensagem de erro caso o ponteiro para o node (1) seja NULL.
 */
void set_previus(DLLN_t *, DLLN_t *);

#endif