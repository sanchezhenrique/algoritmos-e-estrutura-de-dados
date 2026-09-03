#include <stdlib.h>
#include "item.h"

struct item {
    int id;
    char mensagem[51];
};

ITEM* item_criar(int id, char* mensagem) {
    ITEM* novo = (ITEM*) malloc(sizeof(ITEM));
    if (novo != NULL) {
        novo->id = id;
        
        // Cópia manual da string sem usar string.h
        int i = 0;
        while (mensagem[i] != '\0' && i < 50) {
            novo->mensagem[i] = mensagem[i];
            i++;
        }
        novo->mensagem[i] = '\0';
    }
    return novo;
}

void item_apagar(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
    }
}

int item_get_id(ITEM *item) {
    return item->id;
}

char* item_get_mensagem(ITEM *item) {
    return item->mensagem;
}