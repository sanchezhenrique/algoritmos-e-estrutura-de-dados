#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_{ 
    char chave;
};

ITEM *item_criar (char chave){
    ITEM *item = (ITEM *) malloc(sizeof(ITEM));
    if (item != NULL){
        item->chave = chave;
        return item;
    }
    return NULL;
}

bool item_apagar(ITEM **item){
    if (*item != NULL){
        free (*item);
        *item = NULL;
        return true;
    }
    return false;
}

char item_get_chave(ITEM *item){
    if (item != NULL) return item->chave;
    exit(1);
}
