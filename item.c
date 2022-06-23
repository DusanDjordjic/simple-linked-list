#include <stdio.h>
#include "item.h"

void item_print(Item* item)
{
    if(item == NULL)
        return;
    
    printf("%d | %s | %d\n", item->id, item->name, item->name_len);
}
