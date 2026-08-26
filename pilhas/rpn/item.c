#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_{ 
        float chave;
        /*outros componentes*/
};

ITEM *item_criar (float chave){
          ITEM *item;
          
          item = (ITEM *) malloc(sizeof(ITEM));
          
          if (item != NULL){
             item->chave = chave;
             return(item);
          }
          return(NULL);
}

bool item_apagar(ITEM **item){
   if (*item != NULL){
      free (*item);
      *item = NULL; /*Boa pr�tica!*/
      return(true);
   }
   return(false);
}

float item_get_chave(ITEM *item){
    if (item != NULL)
      return(item->chave);
    exit(1);
}


bool item_set_chave(ITEM *item, float chave){
  if (item != NULL){
    item->chave = chave;
    return (true);
  }
  return (false);
}

void item_imprimir(ITEM *item){
     if (item != NULL){
        printf("\n-->item chave: %d\n", item->chave);
     }
}
