#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "utils.h"
#include "defs.h"

void print_list(Node* head)
{
    if(head == NULL)
    {
        printf("No items added yet.\n");
        return;
    }

    while(head != NULL)
    {
        printf("Item %d: %s\n", head->id, head->name);
        head = head->next;
    }
}

int add_item_to_end(Node* head)
{
    
    // See main.c case '2'
    if(head == NULL)
        return 0;

    while(head->next != NULL)
        head = head->next;

    // Id of next node will be last id added + 1
    head->next = add_item(head->id + 1);
    return 0;
}

Node* add_item(int next_id)
{
    Node* node = (Node*)malloc(sizeof(Node));

    if(node == NULL)
    {
        perror("Error while allocating memory for new node");
        exit(-1);
    }

    // Add 1 to last id so we get unique ids
    node->id = next_id;
    node->name = get_string(NAME_SIZE, "Enter new name");
    node->next = NULL;
    return node;
}

Node* remove_item(Node* head)
{
    int id_to_remove = -1;
    printf("Enter an id to remove: ");
    scanf("%d", &id_to_remove);
    // Clear input buffer or leading white space and '\n'
    clear_ibuffer();

    if(head == NULL)
    {
        printf("No item found with an id of %d\n", id_to_remove);
        return NULL;
    }

    if(head->id == id_to_remove)
    {
        Node* tmp = head->next;
        printf("Removed item with an id of %d\n", id_to_remove);
        printf("It was head\n");
        free(head);
        return tmp;
    }
    
    if(head->next == NULL)
    {
        printf("No item found with an id of %d\n", id_to_remove);
        printf("head->next == NULL\n");
        return head;
    }

    while(head->next->id != id_to_remove)
    {
        if(head->next == NULL)
        {
            printf("No item found with an id of %d\n", id_to_remove);
            return 0;
        }
        head = head->next;
    } 

    Node* tmp = head->next->next;
    free(head->next);
    printf("Removed item with an id of %d\n", id_to_remove);
    printf("At the end\n");
    head->next = tmp;
    return head;
}

void free_list(Node* head)
{
    Node* tmp;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

Node* load_list()
{
    return NULL;
    Node* head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    head->name = "Head";
    head->next = NULL;
    return head;
}








