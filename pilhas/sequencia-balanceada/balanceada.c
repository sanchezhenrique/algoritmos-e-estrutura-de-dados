#include <stdbool.h>
#include "Pilha.h"

bool balanceada(char *sequencia){
  PILHA *p = pilha_criar();

  int i = 0;

  while(sequencia[i] != '\0'){

    if(sequencia[i] == '[' || sequencia[i] == '{' || sequencia[i] == '('){
      if(!pilha_cheia(p)){
        pilha_empilhar(p, item_criar(sequencia[i]));
      }
    }

    else if(sequencia[i] == ']' || sequencia[i] == '}' || sequencia[i] == ')'){
      if(pilha_vazia(p)){
        pilha_apagar(&p);
        return false;
      }

      if ((sequencia[i] == ')' && item_get_chave(pilha_topo(p)) == '(') ||
          (sequencia[i] == ']' && item_get_chave(pilha_topo(p)) == '[') ||
          (sequencia[i] == '}' && item_get_chave(pilha_topo(p)) == '{')) {

        ITEM *item_rem = pilha_desempilhar(p);
        item_apagar(&item_rem);
        
      } 
        else{
          pilha_apagar(&p);
          return false;
        }
      }

      i++;
    }

  if(pilha_vazia(p)){
    pilha_apagar(&p);
    return true;
  } else{
    pilha_apagar(&p);
    return false;
  }
}