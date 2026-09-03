#ifndef ITEM_H
#define ITEM_H

typedef struct item ITEM;

ITEM* item_criar(int id, char* mensagem);
void item_apagar(ITEM **item);
int item_get_id(ITEM *item);
char* item_get_mensagem(ITEM *item);

#endif