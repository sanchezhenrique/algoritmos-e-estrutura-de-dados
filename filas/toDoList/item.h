#ifndef ITEM_H
#define ITEM_H

typedef struct item ITEM;

ITEM* item_criar(int id, int prioridade);
void item_apagar(ITEM **item);
int item_get_id(ITEM *item);
int item_get_prioridade(ITEM *item);
void item_set_prioridade(ITEM *item, int prioridade);

#endif
