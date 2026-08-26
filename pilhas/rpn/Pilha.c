#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

typedef struct no NO;
struct no {
     ITEM* item;
     NO* anterior;
};

struct pilha {
    NO* topo;
    int tamanho;
};
 

PILHA* pilha_criar(void) {
    PILHA* pilha = (PILHA* ) malloc(sizeof (PILHA));
    if (pilha != NULL) {
      pilha->topo = NULL;
      pilha->tamanho = 0;
    }
    return (pilha);
}

void pilha_apagar(PILHA** pilha) {
   NO* paux;
   
   if ( ((*pilha) !=NULL) && (!pilha_vazia(*pilha)) ) {
    
     while ((*pilha)->topo != NULL) {
        paux = (*pilha)->topo;
        (*pilha)->topo = (*pilha)->topo->anterior;
        
        item_apagar(&paux->item);
       /*/apagar_no(paux); ou*/
       paux->anterior = NULL;
       free(paux);
       paux = NULL;
       
     }
   }

   free(*pilha);
   *pilha = NULL;
}

bool pilha_cheia(PILHA *pilha){
  if(pilha != NULL){  
    NO *pnovo = (NO *) malloc(sizeof (NO));
    if (pnovo != NULL){
      free (pnovo);
      return (false);
    }
    return(true);
  }
  return(false);
}

bool pilha_vazia(PILHA *pilha) {
    if(pilha != NULL)
      return ((pilha->tamanho == 0) ? true : false);
    return(false); //pilha n�o existe, ent�o, n�o h� como estar vazia.
 }

int pilha_tamanho(PILHA *pilha) {
    return ((pilha != NULL) ? pilha->tamanho : -11);
}

ITEM* pilha_topo(PILHA *pilha) {
   if ((pilha!=NULL)&& (!pilha_vazia(pilha)) ) {
      return (pilha->topo->item);
   }
   return (NULL);
}
 
bool pilha_empilhar(PILHA *pilha, ITEM* item) {
    if(!pilha_cheia(pilha)){
      NO *pnovo = (NO *) malloc(sizeof (NO));
      if (pnovo != NULL) {
        pnovo->item = item;
        pnovo->anterior = pilha->topo;
        pilha->topo = pnovo;
        pilha->tamanho++;
        return (true);
      }
    }
    return (false);
}

ITEM* pilha_desempilhar(PILHA* pilha) {
   if ( (pilha != NULL) && (!pilha_vazia(pilha)) ) {
     NO* pno = pilha->topo;
     ITEM* item = pilha->topo->item;
     
     pilha->topo = pilha->topo->anterior;
     pno->anterior=NULL; 
     
     free(pno); 
     pno=NULL;
     
     pilha->tamanho--;
     
     return (item);
   }
   return (NULL);
}

void pilha_print(PILHA* p){
     NO* ptr;
     ptr = p->topo;
     
     while (ptr !=NULL){
           printf("\n%d, ", item_get_chave(ptr->item));
           ptr = ptr->anterior;
     }
     
}


     
