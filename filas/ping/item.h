#ifndef ITEM_H
#define ITEM_H

typedef struct item ITEM;

ITEM* item_criar(char* acao);
void item_apagar(ITEM **item);
char* item_get_acao(ITEM *item);

#endif
