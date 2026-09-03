#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

typedef struct _no{
  ITEM *item;
  struct _no *prox;
} NO;

struct fila {
  NO *inicio;
  NO *fim;
  int tamanho;
};

FILA* fila_criar(){
  FILA *f = malloc(sizeof(FILA));
  if(f != NULL){
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
  } 
  return f;
}

bool fila_inserir(FILA *fila, ITEM *item){
  if(fila == NULL || item == NULL) return false;

  NO *novo = malloc(sizeof(NO));
  if(novo == NULL) return false;

  novo->item = item;
  novo->prox = NULL;

  if(fila_vazia(fila)){
    fila->inicio = novo;
    fila->fim = novo;
  } else{
    fila->fim->prox = novo;
    fila->fim = novo;
  }

  fila->tamanho++;
  return true;
}

ITEM* fila_remover(FILA *fila){
  if(fila == NULL || fila_vazia(fila)) return NULL;

  NO *removido = fila->inicio;
  ITEM *item = removido->item;

  fila->inicio = removido->prox;
  
  if(fila->inicio == NULL) fila->fim = NULL;
  

  free(removido);
  fila->tamanho--;
  return item;
}

void fila_apagar(FILA **fila){
  ITEM *item;

  if(fila == NULL || *fila == NULL) return;

  while(!fila_vazia(*fila)){
    item = fila_remover(*fila);
    item_apagar(&item);
  }

  free(*fila);
  *fila = NULL;
}


bool fila_vazia(FILA *fila){
  return fila == NULL || fila->tamanho == 0;
}

int fila_tamanho(FILA *fila){
  if(fila != NULL) return fila->tamanho;
  else return 0;
}

void fila_imprimir_status(FILA *fila){
  NO *atual;

  if(fila_vazia(fila)) printf("FILA VAZIA!");

  printf("inicio->");
  atual = fila->inicio;

  while(atual != NULL){
    printf("%s \n", item_get_mensagem(atual->item));
    atual = atual->prox;
  }
  printf("<-fim");
}