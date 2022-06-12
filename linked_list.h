#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "item.h"

struct Node {
    Item* item;
    struct Node* next;
};

typedef struct Node Node;

void print_list(Node* head);
void print_item(Node* head);
int add_item(Node** phead);
int remove_item(Node** head);
int edit_item(Node* head);
void free_list(Node* head);
Node* load_list();

#endif
