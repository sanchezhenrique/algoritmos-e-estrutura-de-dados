#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include "item.h"

typedef struct pilha PILHA;

PILHA* pilha_criar(void);
bool pilha_push(PILHA *p, ITEM *item);
ITEM* pilha_pop(PILHA *p);
void pilha_apagar(PILHA **p);
bool pilha_vazia(PILHA *p);

#endif
