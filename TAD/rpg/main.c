#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "personagem.h"
#define MAX_BUFFER 500

int main(){
  char *nome1 = malloc(sizeof(char) * MAX_BUFFER);
  char *nome2 = malloc(sizeof(char) * MAX_BUFFER);

  int vida1, ataque1, defesa1;
  int vida2, ataque2, defesa2;

  fgets(nome1, MAX_BUFFER, stdin);
  nome1[strcspn(nome1, "\r\n")] = '\0';
  scanf("%d %d %d", &vida1, &ataque1, &defesa1);
  getchar(); // Limpa \r
  getchar(); //Limpa \n

  fgets(nome2, MAX_BUFFER, stdin);
  nome2[strcspn(nome2, "\r\n")] = '\0';
  scanf("%d %d %d", &vida2, &ataque2, &defesa2);
  getchar(); // Limpa \r
  getchar(); //Limpa \r
  
  PERSONAGEM *p1 = personagem_criar(nome1, vida1, ataque1, defesa1);
  free(nome1);

  PERSONAGEM *p2 = personagem_criar(nome2, vida2, ataque2, defesa2);
  free(nome2);

  personagem_atacar(p1,p2);
  personagem_atacar(p2,p1);

  personagem_print(p1);
  personagem_print(p2);

  personagem_apagar(&p1);
  personagem_apagar(&p2);
}