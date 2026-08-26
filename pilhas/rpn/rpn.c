#include <stdio.h>
#include <stdlib.h> 
#include "Pilha.h"

float rpn (char* s){
  PILHA *p = pilha_criar();
  int i = 0; 
  while(s[i] != '\0'){
    switch (s[i]){
      case '+':
        if(!pilha_vazia(p)){
          ITEM *x = pilha_desempilhar(p);
          ITEM *y = pilha_desempilhar(p);
          ITEM *r = item_criar((float)item_get_chave(y) + item_get_chave(x));
          pilha_empilhar(p,r);
          item_apagar(&x);
          item_apagar(&y);
        }
      break;
    
      case '-':
        if(!pilha_vazia(p)){
          ITEM *x = pilha_desempilhar(p);
          ITEM *y = pilha_desempilhar(p);
          ITEM *r = item_criar((float)item_get_chave(y) - item_get_chave(x));
          pilha_empilhar(p,r);
          item_apagar(&x);
          item_apagar(&y);
        }
      break;

      case '*':
        if(!pilha_vazia(p)){
          ITEM *x = pilha_desempilhar(p);
          ITEM *y = pilha_desempilhar(p);
          ITEM *r = item_criar((float)item_get_chave(y) * item_get_chave(x));
          pilha_empilhar(p,r);
          item_apagar(&x);
          item_apagar(&y);
        }
      break;

      case '/':
        if(!pilha_vazia(p)){
          ITEM *x = pilha_desempilhar(p);
          ITEM *y = pilha_desempilhar(p);
          ITEM *r = item_criar((float) item_get_chave(y) / item_get_chave(x));
          pilha_empilhar(p,r);
          item_apagar(&x);
          item_apagar(&y);
        }
      break;

      default:
        ITEM *x = item_criar((float)(s[i] - '0'));
        pilha_empilhar(p,x);
        break;
    }
    i++;
  }

  ITEM *resultado = pilha_desempilhar(p);
  pilha_apagar(&p);
  float x = item_get_chave(resultado);
  item_apagar(&resultado);
  return x;
}