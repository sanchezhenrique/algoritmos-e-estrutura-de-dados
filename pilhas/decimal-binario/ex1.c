#include <stdio.h>
#define MAX_BITS 32

int main(){
  unsigned int numero;
  int bits[MAX_BITS];
  int quantidade = 0;
  scanf("%u", &numero);

  while(numero != 0){
    bits[quantidade] = numero % 2;
    numero /= 2;
    quantidade++;
  }

  for(quantidade--; quantidade >= 0; quantidade--){
    printf("%u", bits[quantidade]);
  }
}
/*
*  Problemas:
*   Leitura na ordem inversa;
*   Vetor de tamanho fixo pré-definido;
*   
*/