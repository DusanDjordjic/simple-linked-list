#include <stdio.h>
#include "linked_list.h"

void print_list(Node* head)
{

    while(head != NULL)
    {
        printf("Item: %d\t", head->value);
        head = head->next;
    }
    printf("\n");
}

