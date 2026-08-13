#ifndef PERSONAGEM_H
  #define PERSONAGEM_H
  #include <stdbool.h>

  typedef struct personagem PERSONAGEM;

  PERSONAGEM* personagem_criar(char* nome, int vida, int ataque, int defesa);

  void personagem_apagar(PERSONAGEM **p);
  
  int personagem_get_vida(PERSONAGEM *p);
  
  void personagem_print(PERSONAGEM *p); //Imprime: "Nome: [nome] | Vida: [PV]"
  
  bool personagem_atacar(PERSONAGEM *atacante, PERSONAGEM *defensor);
    /* Simula um ataque de um personagem a outro.
    * O dano é calculado pela diferença (ataque do atacante - defesa do defensor).
    * Se o dano for maior que zero, é subtraído dos Pontos de Vida do defensor.
    * Retorna 1 se o defensor foi derrotado (PV <= 0), ou 0 caso contrário.*/

    #endif