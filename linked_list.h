#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node Node;

void print_list(Node* head);
#endif
