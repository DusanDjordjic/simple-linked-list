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

int add_item(Node** phead)
{
     
    Node* node = (Node*)malloc(sizeof(Node));

    if(node == NULL)
    {
        perror("Error while allocating memory for new node");
        return -1;
    }
    
    int next_id = 1; 
    if(*phead == NULL)
        *phead = node;
    else
    {
        Node* tmphead = *phead;
        while(tmphead->next != NULL)
            tmphead = tmphead->next;
        
        tmphead->next = node;
        next_id = tmphead->id + 1;
    }
    
    node->id = next_id;
    node->name = get_string(NAME_SIZE, "Enter new name");
    node->next = NULL;
    return 0;
}


int remove_item(Node** phead)
{
    int id_to_remove = -1;
    printf("Enter an id to remove: ");
    scanf("%d", &id_to_remove);
    // Clear input buffer or leading white space and '\n'
    clear_ibuffer();

    if(id_to_remove < 1)
    {
        printf("Invalid id: %d", id_to_remove);
        return -1;
    }

    
    Node* tmphead = *phead;
    Node* prev = NULL;
    
    if(tmphead == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    if(tmphead->id == id_to_remove)
    {
        *phead = tmphead->next;
        printf("Removed item with an id of %d\n", id_to_remove);
        free(tmphead);
        return -1;
    }
    
    // 1 Dusan
    // 2 Joka
    // 3 Aca 
    // 4 Cone

    // 
    while(tmphead != NULL && tmphead->id != id_to_remove)
    {
        prev = tmphead;
        tmphead = tmphead->next;
    } 
    
    if(tmphead == NULL)
    {
        printf("No item found with an id of %d\n", id_to_remove);
        return -1;
    }
    
    prev->next = tmphead->next;
    printf("Removed item with an id of %d\n", id_to_remove);
    free(tmphead);
    return 0;
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

