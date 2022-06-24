#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "item.h"

struct Node {
    void* item;
    struct Node* next;
};

typedef struct Node Node;
typedef void (*ioperation) (void*);
typedef void* (*igenerate) ();

void print_list(Node* head,ioperation iprint);
void print_item(Node* head, ioperation iprint);
int add_item(Node** phead, igenerate igen);
int remove_item(Node** head, ioperation ifree);
int edit_item(Node* head, ioperation iprint, ioperation ifree, igenerate igen);
int reverse_list(Node** head);
void free_list(Node** phead, ioperation ifree);
void load_list(const char* filename, Node** phead, ioperation ifree);
void save_list(Node* head, const char* filename);

#endif
