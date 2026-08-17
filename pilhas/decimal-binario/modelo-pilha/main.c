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
    unsigned int numero;
    scanf("%u", &numero);
    if(numero == 0){
        printf("0");
        return EXIT_SUCCESS;
    }

    PILHA *pilha = pilha_criar();

    if (pilha == NULL) {
        printf("Nao foi possivel criar a pilha.\n");
        return EXIT_FAILURE;
    }

    while(numero != 0){
        empilhar_valor(pilha, numero % 2);
        numero /=2;
    }

    printf("Bits: %d\n", pilha_tamanho(pilha));
    printf("Número binário: ");

    pilha_imprimir(pilha);

    pilha_apagar(&pilha);
    return EXIT_SUCCESS;
}