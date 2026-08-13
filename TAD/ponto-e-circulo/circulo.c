#include <stdlib.h>
#include <stdbool.h>
#include "circulo.h"
#include "ponto.h"

struct circulo_
{
  PONTO *centro;
  float raio;
};

CIRCULO *circulo_criar (PONTO *p, float raio){
  if(p == NULL ||raio <= 0) return NULL;

  CIRCULO *c = malloc(sizeof(CIRCULO));
  if(c == NULL) return NULL;

  c->centro = p;
  c->raio = raio;

  return c;
}


bool circulo_set_ponto (CIRCULO *c, PONTO *p){
  if(c != NULL && p != NULL){ 
    ponto_apagar(&c->centro);
    c->centro = p;
    return true;
  }
  else return false;
}

bool circulo_set_raio (CIRCULO *c, float raio){
  if(c != NULL && raio > 0){
    c->raio = raio;
    return true;
  } else return false;
}

PONTO *circulo_get_ponto (CIRCULO *c){
  if(c == NULL) return NULL;

  return c->centro;
}

float circulo_get_raio (CIRCULO *c){
  if(c == NULL) return -1;

  return c->raio;
}

void circulo_apagar (CIRCULO **circulo){
  if(circulo != NULL && *circulo != NULL){
    ponto_apagar(&(*circulo)->centro); 
    free(*circulo);
    *circulo = NULL;
  }
}