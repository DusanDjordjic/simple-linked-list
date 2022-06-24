#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "utils.h"
#include "defs.h"

static int next_id = 1;

void item_print(void* item)
{
    if(item == NULL)
        return;
    
    printf("%d | %s | %d\n", ((Item*)item)->id, ((Item*)item)->name, ((Item*)item)->name_len);
}

void* item_gen()
{
    
    Item* new_item = (Item*) malloc(sizeof(Item));
    new_item->id = next_id++;
    new_item->name = get_string(NAME_SIZE, "Enter new name", &new_item->name_len);
    return (void*)new_item;
}

void item_free(void* item)
{
    free(((Item*)item)->name);
    free((Item*)item);
}
