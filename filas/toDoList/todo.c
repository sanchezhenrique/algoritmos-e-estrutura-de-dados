#include <stdio.h>
#include "fila_prioridade.h"

int main(){
  FILA *f = fila_criar();
  while(1){
    char comando[7];
    scanf("%s", comando);
    if(f == NULL) return 1;

    switch (comando[0]){
      case 'N':{
        int id, prioridade;
        scanf("%d %d", &prioridade, &id);

        ITEM *novo = item_criar(id, prioridade);
        if(novo == NULL) return 1;

        if(!fila_inserir(f, novo)) return 1;

        printf("[TO-DO] Tarefa %d adicionada (Prioridade %d).\n", id, prioridade);
        break;
      }

      case 'F':{
        if(fila_vazia(f)) printf("[ALERTA] Tudo limpo! Nenhuma tarefa pendente.\n");
        else{
          ITEM *removido = fila_remover(f);
          int id = item_get_id(removido);

          printf("[FOCO] Tarefa %d concluida. Um passo mais perto das ferias!\n", id);
          item_apagar(&removido);
        }
        break;
      }

      case 'T':{
        if(fila_vazia(f)) printf("[ALERTA] Tudo limpo! Nenhuma tarefa pendente.\n");
        else{
          ITEM *removido = fila_remover(f);
          item_set_prioridade(removido, 1);
          if(!fila_inserir(f, removido)) return 1;

          printf("[VICIO] Tarefa %d adiada. O algoritmo venceu...\n", item_get_id(removido));
        }
        break;
      }

      case 'L':
        fila_imprimir(f);
      break;

      case 'D':
        int tamanho = fila_tamanho(f);
        printf("[FIM] %d tarefa(s) ficam para amanha. Boa noite.\n", tamanho);
        fila_apagar(&f);
        return 0;
    }
  }
}