#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct Node {
    char* name;
    int id;
    struct Node* next;
};

typedef struct Node Node;

void print_list(Node* head);
int add_item(Node **phead);
Node* remove_item(Node* head);
void free_list(Node* head);
Node* load_list();

#endif
