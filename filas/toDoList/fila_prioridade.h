#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include <stdbool.h>
#include "item.h"

typedef struct fila FILA;

FILA* fila_criar(void);
bool fila_inserir(FILA *f, ITEM *item);
ITEM* fila_remover(FILA *f);
void fila_apagar(FILA **f);
bool fila_vazia(FILA *f);
int fila_tamanho(FILA *f);
void fila_imprimir(FILA *f);

#endif
