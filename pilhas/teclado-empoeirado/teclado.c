#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void teclado(char *sequencia){
  PILHA *p = pilha_criar();
  int i = 0;

  while(sequencia[i] != '\0'){
    if(pilha_vazia(p)) pilha_empilhar(p, item_criar(sequencia[i]));
    else{
      char chave_topo = item_get_chave(pilha_topo(p));
      if(chave_topo == sequencia[i]){
        i++;
        continue;
      } else{
        pilha_empilhar(p, item_criar(sequencia[i]));
      }
    }
    i++;
  }
  
  int tamanho_pilha = pilha_tamanho(p);

  char *s = malloc(sizeof(char) * (tamanho_pilha +1));
  s[tamanho_pilha] = '\0';
  i = tamanho_pilha - 1;

  while(i >= 0){
    ITEM *char_removido = pilha_desempilhar(p);
    s[i] = item_get_chave(char_removido);
    item_apagar(&char_removido);
    i--;
  }

  pilha_apagar(&p);

  printf("%s\n", s);
  free(s);
}
