#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "personagem.h"

 struct personagem{
  char* nome;
  int vida;
  int ataque;
  int defesa;
 };


PERSONAGEM* personagem_criar(char* nome, int vida, int ataque, int defesa){
  if(nome == NULL || vida <= 0) {
    return NULL;
  }
  PERSONAGEM *p = malloc(sizeof(PERSONAGEM));
  if(p == NULL) return NULL;

  p->nome = malloc(sizeof(char) * (strlen(nome) + 1));
  strcpy(p->nome, nome);

  p->vida = vida;
  p->ataque = ataque;
  p->defesa = defesa;
  
  return p;
}

void personagem_apagar(PERSONAGEM **p){
  if(p != NULL && *p != NULL && (*p)->nome != NULL){
    free((*p)->nome);
    free(*p);
    *p = NULL;
  }
}

int personagem_get_vida(PERSONAGEM *p){
  if(p != NULL){
    return p->vida;
  } else return 0;
}
  
void personagem_print(PERSONAGEM *p){
  if(p != NULL){
    printf("Nome: %s | Vida: %d\n", p->nome, p->vida);
  }
}
  
bool personagem_atacar(PERSONAGEM *atacante, PERSONAGEM *defensor){
  if(atacante != NULL && defensor != NULL && atacante->vida >= 0){
    int dano = atacante->ataque - defensor->defesa;
    if(dano > 0){
      defensor->vida -= dano;
      if(defensor->vida > 0){
        return false;
      }
      else{
        return true;
      }
    } else return false;
  } else return false;
}