#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

static void empilhar_valor(PILHA *pilha, int valor) {
    ITEM *item = item_criar(valor);

    if (item == NULL || !pilha_empilhar(pilha, item)) {
        item_apagar(&item);
        printf("Nao foi possivel empilhar %d.\n", valor);
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    PILHA *pilha = pilha_criar();
    ITEM *removido;

    if (pilha == NULL) {
        printf("Nao foi possivel criar a pilha.\n");
        return EXIT_FAILURE;
    }

    empilhar_valor(pilha, 7);
    empilhar_valor(pilha, 2);
    empilhar_valor(pilha, 4);

    pilha_imprimir(pilha);
    printf("Tamanho: %d\n", pilha_tamanho(pilha));
    printf("Elemento no topo: %d\n", item_get_chave(pilha_topo(pilha)));

    removido = pilha_desempilhar(pilha);
    printf("Elemento desempilhado: %d\n", item_get_chave(removido));
    item_apagar(&removido);

    pilha_imprimir(pilha);
    pilha_inverter(pilha);
    printf("Depois de inverter:\n");
    pilha_imprimir(pilha);

    pilha_apagar(&pilha);
    return EXIT_SUCCESS;
}