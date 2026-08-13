#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct circulo CIRCULO;

CIRCULO *criar_circulo (float raio);

void circulo_apagar(CIRCULO **circulo);

int circulo_eh_valido(CIRCULO *circulo);

float circulo_get_raio(CIRCULO *circulo);

int circulo_set_raio(CIRCULO *circulo, float novo_raio);

int circulo_cabe_quadrado(CIRCULO *circulo, float lado_quadrado);

void circulo_imprimir(CIRCULO *circulo);

#endif