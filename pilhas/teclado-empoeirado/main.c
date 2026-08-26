#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(int argc, char *argv[]) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char str_sequencia[200];
    for (int i = 0; i < n; i++) {
        scanf(" %199[^\n]", str_sequencia);; // Lê a linha inteira, incluindo espaços
        teclado(str_sequencia);
    }
    return 0;
}
