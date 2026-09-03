#include <stdlib.h>
#include "item.h"

struct item {
    char acao[51];
};

ITEM* item_criar(char* acao) {
    ITEM* novo = (ITEM*) malloc(sizeof(ITEM));
    if (novo != NULL) {
        int i = 0;
        while (acao[i] != '\0' && i < 50) {
            novo->acao[i] = acao[i];
            i++;
        }
        novo->acao[i] = '\0';
    }
    return novo;
}

void item_apagar(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
    }
}

char* item_get_acao(ITEM *item) {
    return item->acao;
}
