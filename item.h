#ifndef _ITEM_H_
#define _ITEM_H_

struct Item
{
    int id;
    int name_len;
    char* name;
};

typedef struct Item Item;


void item_print(void* item);
void* item_gen();
void item_free(void* item);

#endif
