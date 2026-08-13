#include <stdio.h>
#include "circulo.h"
#include "quadrado.h"

int main(void) {
    /*
     * O main.c e o CLIENTE dos dois TADs.
     * Ele conhece as funcoes publicas, mas nao conhece os campos internos.
     */

    CIRCULO *circulo = criar_circulo(3.0f);
    QUADRADO *quadrado = criar_quadrado(5.0f);

    /* Sempre verificamos se a construcao funcionou. */
    if (circulo == NULL || quadrado == NULL) {
        fprintf(stderr, "Erro ao criar as figuras.\n");
        circulo_apagar(&circulo);
        quadrado_apagar(&quadrado);
        return 1;
    }

    printf("=== FIGURAS CRIADAS ===\n");
    circulo_imprimir(circulo);
    quadrado_imprimir(quadrado);

    /*
     * Exemplo importante de encapsulamento:
     *
     * NAO fazemos circulo->raio nem quadrado->lado.
     * Usamos get para receber uma COPIA do valor de cada campo.
     */
    float raio = circulo_get_raio(circulo);
    float lado = quadrado_get_lado(quadrado);

    printf("\n=== TESTE 1 ===\n");
    printf("Circulo de raio %.2f dentro do quadrado de lado %.2f? ",
           raio, lado);

    if (circulo_cabe_quadrado(circulo, lado)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    printf("Quadrado de lado %.2f dentro do circulo de raio %.2f? ",
           lado, raio);

    if (quadrado_cabe_circulo(quadrado, raio)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    /*
     * Podemos mudar as dimensoes usando a funcao da interface (e.g. setters).
     * A validacao continua sendo responsabilidade de cada TAD.
     */
    circulo_set_raio(circulo, 4.0f);
    quadrado_set_lado(quadrado, 4.0f);

    raio = circulo_get_raio(circulo);
    lado = quadrado_get_lado(quadrado);

    printf("\n=== TESTE 2: APOS ALTERAR AS FIGURAS ===\n");
    circulo_imprimir(circulo);
    quadrado_imprimir(quadrado);

    printf("Circulo dentro do quadrado? %s\n",
           circulo_cabe_quadrado(circulo, lado) ? "SIM" : "NAO");

    printf("Quadrado dentro do circulo? %s\n",
           quadrado_cabe_circulo(quadrado, raio) ? "SIM" : "NAO");

    /* Teste de validacao: o TAD deve recusar um valor invalido. */
    printf("\n=== TESTE 3: VALIDACAO ===\n");
    if (!quadrado_set_lado(quadrado, -2.0f)) {
        printf("O TAD QUADRADO recusou corretamente o lado -2.\n");
    }

    /* Liberacao da memoria alocada pelos construtores. */
    circulo_apagar(&circulo);
    quadrado_apagar(&quadrado);

    return 0;
}