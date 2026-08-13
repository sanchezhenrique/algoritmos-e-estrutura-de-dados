#ifndef QUADRADO_H
#define QUADRADO_H

typedef struct quadrado QUADRADO;

QUADRADO *criar_quadrado (float raio);

void quadrado_apagar(QUADRADO **quadrado);

int quadrado_eh_valido(QUADRADO *quadrado);

float quadrado_get_lado(QUADRADO *quadrado);

int quadrado_set_lado(QUADRADO *quadrado, float novo_raio);

int quadrado_cabe_circulo(QUADRADO *quadrado, float raio);

void quadrado_imprimir(QUADRADO *quadrado);

#endif