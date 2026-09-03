#include <stdlib.h>
#include "item.h"

struct item {
    int id;
    int prioridade;
};

ITEM* item_criar(int id, int prioridade) {
    ITEM* novo = (ITEM*) malloc(sizeof(ITEM));
    if (novo != NULL) {
        novo->id = id;
        novo->prioridade = prioridade;
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

int item_get_prioridade(ITEM *item) {
    return item->prioridade;
}

void item_set_prioridade(ITEM *item, int prioridade) {
    if (item != NULL) {
        item->prioridade = prioridade;
    }
}
