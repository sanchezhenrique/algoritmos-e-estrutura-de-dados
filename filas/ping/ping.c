#include <stdio.h>
#include "pilha.h"
#include "fila.h"

int main(){
  char comando[5];
  DEQUE *deq = deque_criar();
  PILHA *ping = pilha_criar();

  while(scanf(" %s", comando) == 1){
    switch (comando[0]){

      case 'd': {
        char acao[51];
        scanf(" %s", acao);
        ITEM *novo = item_criar(acao);

        if(novo == NULL){
          deque_apagar(&deq);
          pilha_apagar(&ping);
          return 1;
        }

        if(!deque_inserir_fim(deq, novo)){
          deque_apagar(&deq);
          pilha_apagar(&ping);
          return 1;
        }
        break;
      }

      case 'r': {
        ITEM *item = deque_remover_inicio(deq);
        if(item == NULL) continue;;
        printf("Executando %s\n", item_get_acao(item));
        item_apagar(&item);
        break;
      }

      case 'p': {
        ITEM *item = deque_remover_inicio(deq);
        if(item == NULL) continue;

        if(!pilha_push(ping, item)){
          deque_apagar(&deq);
          pilha_apagar(&ping);
          return 1;
        }
        break;
      }

      case 'u': {
        ITEM *item = pilha_pop(ping);
        if(item == NULL) continue;

        if(!deque_inserir_inicio(deq,item)){
          deque_apagar(&deq);
          pilha_apagar(&ping);
          return 1;
        }
        break;
      }
    }
  }
  deque_apagar(&deq);
  pilha_apagar(&ping);
}