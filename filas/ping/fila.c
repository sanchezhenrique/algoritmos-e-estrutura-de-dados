#include <stdlib.h>
#include "fila.h"

typedef struct no_deque NO_DEQUE;

struct no_deque {
    ITEM *item;
    NO_DEQUE *prox;
    NO_DEQUE *ant;
};

struct deque {
    NO_DEQUE *inicio;
    NO_DEQUE *fim;
    int tamanho;
};

DEQUE* deque_criar(void) {
    DEQUE *d = (DEQUE*) malloc(sizeof(DEQUE));
    if (d != NULL) {
        d->inicio = NULL;
        d->fim = NULL;
        d->tamanho = 0;
    }
    return d;
}

bool deque_inserir_fim(DEQUE *d, ITEM *item) {
    if (d != NULL) {
        NO_DEQUE *no = (NO_DEQUE*) malloc(sizeof(NO_DEQUE));
        if (no != NULL) {
            no->item = item;
            no->prox = NULL;
            no->ant = d->fim;
            if (deque_vazio(d)) {
                d->inicio = no;
            } else {
                d->fim->prox = no;
            }
            d->fim = no;
            d->tamanho++;
            return true;
        }
    }
    return false;
}

bool deque_inserir_inicio(DEQUE *d, ITEM *item) {
    if (d != NULL) {
        NO_DEQUE *no = (NO_DEQUE*) malloc(sizeof(NO_DEQUE));
        if (no != NULL) {
            no->item = item;
            no->ant = NULL;
            no->prox = d->inicio;
            if (deque_vazio(d)) {
                d->fim = no;
            } else {
                d->inicio->ant = no;
            }
            d->inicio = no;
            d->tamanho++;
            return true;
        }
    }
    return false;
}

ITEM* deque_remover_inicio(DEQUE *d) {
    if (d != NULL && !deque_vazio(d)) {
        NO_DEQUE *p = d->inicio;
        ITEM *it = p->item;
        
        d->inicio = p->prox;
        if (d->inicio != NULL) {
            d->inicio->ant = NULL;
        } else {
            d->fim = NULL; 
        }
        
        free(p);
        d->tamanho--;
        return it;
    }
    return NULL;
}

void deque_apagar(DEQUE **d) {
    if (d != NULL && *d != NULL) {
        while (!deque_vazio(*d)) {
            ITEM *it = deque_remover_inicio(*d);
            item_apagar(&it);
        }
        free(*d);
        *d = NULL;
    }
}

bool deque_vazio(DEQUE *d) {
    return (d == NULL || d->tamanho == 0);
}
