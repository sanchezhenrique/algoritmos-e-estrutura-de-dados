#include <stdio.h>
#include "fila.h"

int main(){
  char comando[10];
  FILA *fila = fila_criar();
  if(fila == NULL) return 1;

  while(scanf(" %s", comando) == 1){
    switch(comando[0]){
      case 'R': {
        int id;
        char mensagem[51];

        scanf("%d", &id);
        scanf(" %s", mensagem);

        ITEM *novo = item_criar(id, mensagem);
        if(novo == NULL) return 1;

        if(!fila_inserir(fila, novo)) return 1;

        printf("[BUFFER] Pacote %d armazenado com sucesso.\n", id);
        break;
      }

      case 'A': {
        if(fila_vazia(fila)){
          printf("[ALERTA] Buffer vazio! Nenhum dado para analisar.\n");
        } else{
          ITEM *item = fila_remover(fila);
          if(item == NULL) return 1;
          printf("[ASTRONAUTA] Analisando pacote %d: %s.\n", item_get_id(item), item_get_mensagem(item));
          item_apagar(&item);
        }
        break;
      }

      case 'S':
        printf("[STATUS] Fila de processamento: ");
        if(fila_vazia(fila)) printf("VAZIA");
        else{
          int n = fila_tamanho(fila);
          for(int i = 0; i < n; i++){
            ITEM *item = fila_remover(fila);
            if(item == NULL) return 1;

            printf("%d", item_get_id(item));

            if (!fila_inserir(fila, item)) return 1;

            if(i != n -1) printf(" -> "); 
          }
        }
        printf("\n");
      break;

      case 'E':
        int n = fila_tamanho(fila);
        printf("[HOUSTON] Tarefa enviada! Memoria liberada: %d pacote(s) descartado(s).\n", n);
        fila_apagar(&fila);
      break;
    }
  }
}