#include <stdlib.h>
#include "pilha.h"

typedef struct no_pilha NO_PILHA;

struct no_pilha {
    ITEM *item;
    NO_PILHA *prox;
};

struct pilha {
    NO_PILHA *topo;
    int tamanho;
};

PILHA* pilha_criar(void) {
    PILHA *p = (PILHA*) malloc(sizeof(PILHA));
    if (p != NULL) {
        p->topo = NULL;
        p->tamanho = 0;
    }
    return p;
}

bool pilha_push(PILHA *p, ITEM *item) {
    if (p != NULL) {
        NO_PILHA *no = (NO_PILHA*) malloc(sizeof(NO_PILHA));
        if (no != NULL) {
            no->item = item;
            no->prox = p->topo;
            p->topo = no;
            p->tamanho++;
            return true;
        }
    }
    return false;
}

ITEM* pilha_pop(PILHA *p) {
    if (p != NULL && !pilha_vazia(p)) {
        NO_PILHA *no = p->topo;
        ITEM *it = no->item;
        p->topo = no->prox;
        free(no);
        p->tamanho--;
        return it;
    }
    return NULL;
}

void pilha_apagar(PILHA **p) {
    if (p != NULL && *p != NULL) {
        while (!pilha_vazia(*p)) {
            ITEM *it = pilha_pop(*p);
            item_apagar(&it);
        }
        free(*p);
        *p = NULL;
    }
}

bool pilha_vazia(PILHA *p) {
    return (p == NULL || p->tamanho == 0);
}
