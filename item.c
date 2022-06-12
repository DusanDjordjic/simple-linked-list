#include <stdio.h>
#include "item.h"

void item_print(Item* item)
{
    if(item == NULL)
        return;

    printf("Item %d: %s\n", item->id, item->name);
}
