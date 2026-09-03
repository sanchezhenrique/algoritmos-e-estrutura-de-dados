#ifndef FILA_H
#define FILA_H

#include <stdbool.h>
#include "item.h"

typedef struct deque DEQUE;

DEQUE* deque_criar(void);
bool deque_inserir_fim(DEQUE *d, ITEM *item);
bool deque_inserir_inicio(DEQUE *d, ITEM *item);
ITEM* deque_remover_inicio(DEQUE *d);
void deque_apagar(DEQUE **d);
bool deque_vazio(DEQUE *d);

#endif
