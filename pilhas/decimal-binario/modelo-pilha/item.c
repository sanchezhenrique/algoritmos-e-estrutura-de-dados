#include "item.h"

#include <stdlib.h>

struct item {
    int chave;
};

ITEM *item_criar(int chave) {
    ITEM *item = malloc(sizeof(ITEM));

    if (item != NULL) {
        item->chave = chave;
    }

    return item;
}

void item_apagar(ITEM **item) {
    if (item == NULL || *item == NULL) {
        return;
    }

    free(*item);
    *item = NULL;
}

int item_get_chave(ITEM *item) {
    return item != NULL ? item->chave : 0;
}

bool item_set_chave(ITEM *item, int chave) {
    if (item == NULL) {
        return false;
    }

    item->chave = chave;
    return true;
}