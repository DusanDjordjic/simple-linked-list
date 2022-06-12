#ifndef _ITEM_H_
#define _ITEM_H_

struct Item
{
    int id;
    char* name;
    int name_len;
};

typedef struct Item Item;


void item_print(Item* item);

#endif
