#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

#define PILHA_CAPACIDADE 100

struct pilha {
    ITEM *itens[PILHA_CAPACIDADE];
    int tamanho;
};

PILHA *pilha_criar(void) {
    PILHA *pilha = malloc(sizeof(PILHA));

    if (pilha != NULL) {
        pilha->tamanho = 0;
    }

    return pilha;
}

void pilha_apagar(PILHA **pilha) {
    int i;

    if (pilha == NULL || *pilha == NULL) {
        return;
    }

    for (i = 0; i < (*pilha)->tamanho; i++) {
        item_apagar(&(*pilha)->itens[i]);
    }

    free(*pilha);
    *pilha = NULL;
}

bool pilha_vazia(PILHA *pilha) {
    return pilha != NULL && pilha->tamanho == 0;
}

bool pilha_cheia(PILHA *pilha) {
    return pilha != NULL && pilha->tamanho == PILHA_CAPACIDADE;
}

int pilha_tamanho(PILHA *pilha) {

    /***
    if (pilha != NULL) {
        return pilha->tamanho;
    } else {
        return -1;
    }
    ***/
    
    return pilha != NULL ? pilha->tamanho : -1;
}

ITEM *pilha_topo(PILHA *pilha) {
    if (pilha == NULL || pilha_vazia(pilha)) {
        return NULL;
    }

    return pilha->itens[pilha->tamanho - 1];
}

bool pilha_empilhar(PILHA *pilha, ITEM *item) {
    if (pilha == NULL || item == NULL || pilha_cheia(pilha)) {
        return false;
    }

    pilha->itens[pilha->tamanho] = item;
    pilha->tamanho++;
    return true;
}

ITEM *pilha_desempilhar(PILHA *pilha) {
    ITEM *item;

    if (pilha == NULL || pilha_vazia(pilha)) {
        return NULL;
    }

    item = pilha->itens[pilha->tamanho - 1];
    pilha->itens[pilha->tamanho - 1] = NULL;
    pilha->tamanho--;
    return item;
}

void pilha_imprimir(PILHA *pilha) {
    int i;

    if (pilha == NULL) {
        return;
    }
    for (i = pilha->tamanho - 1; i >= 0; i--) {
        printf("%d ", item_get_chave(pilha->itens[i]));
    }
    printf("\n");
}

void pilha_inverter(PILHA *pilha) {
    int base;
    int topo;

    if (pilha == NULL) {
        return;
    }

    base = 0;
    topo = pilha->tamanho - 1;

    while (base < topo) {
        ITEM *temporario = pilha->itens[base];
        pilha->itens[base] = pilha->itens[topo];
        pilha->itens[topo] = temporario;
        base++;
        topo--;
    }
}