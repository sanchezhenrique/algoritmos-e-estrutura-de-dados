#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "quadrado.h"

struct quadrado {
  float lado;
};

QUADRADO *criar_quadrado (float lado){
  if(lado <= 0) return NULL;

  QUADRADO *quadrado = malloc(sizeof(quadrado));

  if(quadrado == NULL) return NULL;

  quadrado->lado = lado;

  return quadrado;
}

void quadrado_apagar(QUADRADO **quadrado){
  if(quadrado != NULL && *quadrado != NULL){
    free(*quadrado);
    *quadrado = NULL;
  }
}

int quadrado_eh_valido(QUADRADO *quadrado){
  if(quadrado == NULL){
    return 0;
  }

  return quadrado->lado > 0;
}

float quadrado_get_lado(QUADRADO *quadrado){
  if(!quadrado_eh_valido(quadrado)){
    return -1;
  }
  return quadrado->lado;
}

int quadrado_set_lado(QUADRADO *quadrado, float novo_lado){
  if(quadrado == NULL || novo_lado <= 0){
    return 0;
  }

  quadrado->lado = novo_lado;
  return 1;
}

int quadrado_cabe_circulo(QUADRADO *quadrado, float raio){
  if(!quadrado_eh_valido(quadrado) || raio <= 0){
    return 0;
  }

  return (quadrado->lado * sqrt(2)) <= raio;
}

void quadrado_imprimir(QUADRADO *quadrado){
  if(quadrado_eh_valido(quadrado)){
    printf("O lado do quadrado é: %f", quadrado->lado);
  }
}