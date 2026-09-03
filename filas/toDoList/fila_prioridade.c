#include "fila_prioridade.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
  ITEM *item;
  struct _no *prox;
} NO;

struct fila {
  NO *inicio;
  int tamanho;
};


FILA* fila_criar(void){
  FILA *f = malloc(sizeof(FILA));
  if(f !=NULL){
    f->inicio = NULL;
    f->tamanho = 0;
  }
  return f;
}
bool fila_inserir(FILA *f, ITEM *item){
  if(f == NULL || item == NULL) return false;
  NO *novo = malloc(sizeof(NO));

  if(novo == NULL) return false;

  novo->item = item;
  novo->prox = NULL;

  if(fila_vazia(f)){
    f->inicio = novo;
    f->tamanho++;
    return true;
  }

  if(item_get_prioridade(item) > item_get_prioridade(f->inicio->item)){
    novo->prox = f->inicio;
    f->inicio = novo;
    f->tamanho++;
    return true;
  }

  NO *atual = f->inicio;

  while(atual->prox != NULL && item_get_prioridade(atual->prox->item) >= item_get_prioridade(item)){
    atual = atual->prox;
  }

  novo->prox = atual->prox;
  atual->prox = novo;

  f->tamanho++;
  return true;
}

ITEM* fila_remover(FILA *f){
  if(f == NULL || fila_vazia(f)) return NULL;

  NO *removido = f->inicio;

  f->inicio = removido->prox;

  ITEM *it = removido->item;

  free(removido); removido = NULL;

  f->tamanho--;

  return it;
}
void fila_apagar(FILA **f){
  ITEM *item;

  if(*f == NULL || f == NULL) return;

  while(!fila_vazia(*f)){
    item = fila_remover(*f);
    item_apagar(&item);
  }
  free(*f);
  *f = NULL;
}

bool fila_vazia(FILA *fila){
  return fila == NULL || fila->tamanho == 0;
}

int fila_tamanho(FILA *fila){
  if(fila != NULL) return fila->tamanho;
  else return 0;
}

void fila_imprimir(FILA *f){
  if (fila_vazia(f)) {
    printf("[PENDENTES] VAZIA\n");
    return;
  }

  printf("[PENDENTES] ");
  NO *atual = f->inicio;
  while (atual != NULL) {
    printf("%d", item_get_id(atual->item));

    if (atual->prox != NULL) {
      printf(" -> ");
    }

    atual = atual->prox;
  }
  printf("\n");
}