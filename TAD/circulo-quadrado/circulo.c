#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
struct circulo {
  float raio;
};

CIRCULO *criar_circulo (float raio){
  if(raio <= 0) return NULL;

  CIRCULO *circulo = malloc(sizeof(CIRCULO));

  if(circulo == NULL) return NULL;

  circulo->raio = raio;

  return circulo;
}

void circulo_apagar(CIRCULO **circulo){
  if(circulo != NULL && *circulo != NULL){
    free(*circulo);
    *circulo = NULL;
  }
}

int circulo_eh_valido(CIRCULO *circulo){
  if(circulo == NULL){
    return 0;
  }

  return circulo->raio > 0;
}

float circulo_get_raio(CIRCULO *circulo){
  if(!circulo_eh_valido(circulo)){
    return -1;
  }
  return circulo->raio;
}

int circulo_set_raio(CIRCULO *circulo, float novo_raio){
  if(circulo == NULL || novo_raio <= 0){
    return 0;
  }

  circulo->raio = novo_raio;
  return 1;
}

int circulo_cabe_quadrado(CIRCULO *circulo, float lado_quadrado){
  if(!circulo_eh_valido(circulo) || lado_quadrado <= 0){
    return 0;
  }

  return (2 * circulo->raio) <= lado_quadrado;
}

void circulo_imprimir(CIRCULO *circulo){
  if(circulo_eh_valido(circulo)){
    printf("O raio do circulo é: %f", circulo->raio);
  }
}