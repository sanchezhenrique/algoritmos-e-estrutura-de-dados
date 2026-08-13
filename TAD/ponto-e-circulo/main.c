#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main (){
  float x, y, xC, yC, raio;

  scanf("%f %f %f %f %f", &x, &y, &xC, &yC, &raio);

  PONTO *p = ponto_criar(x, y);
  if(p == NULL) return 1;

  PONTO *pCentro = ponto_criar(xC, yC);
  if(pCentro == NULL) return 1;

  CIRCULO *c = circulo_criar(pCentro, raio);
  if(c == NULL) return 1;
  
  ponto_print(p);

  float raio2 = circulo_get_raio(c);
  PONTO *centro2 = circulo_get_ponto(c);
  float xC2 = ponto_get_x(centro2);
  float yC2 = ponto_get_y(centro2);

  printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f\n", xC2, yC2, raio2);

  ponto_apagar(&p);
  circulo_apagar(&c);
  pCentro = NULL;
  centro2 = NULL;
}