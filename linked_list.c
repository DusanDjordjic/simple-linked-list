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

void print_item(Node* head)
{
    if(head == NULL)
    {
        printf("No items added yet.\n");
        return;
    }

    printf("Item %d: %s\n", head->id, head->name);
}

int add_item(Node** phead)
{
     
    Node* node = (Node*)malloc(sizeof(Node));

    if(node == NULL)
    {
        perror("Error while allocating memory for new node\n");
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
    printf("Item successfully added\n");
    return 0;
}


int remove_item(Node** phead)
{
    if(*phead == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    int id_to_remove = get_int("Enter ad id to remove: ");

    if(id_to_remove < 1)
    {
        printf("Invalid id: %d\n", id_to_remove);
        return -1;
    }

    
    Node* tmphead = *phead;
    Node* prev = NULL;
    

    if(tmphead->id == id_to_remove)
    {
        *phead = tmphead->next;
        printf("Removed item with an id of %d\n", id_to_remove);
        free(tmphead);
        return -1;
    }
    
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

int edit_item(Node* head)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    int id_to_edit = get_int("Enter an item id: ");

    if(id_to_edit < 1)
    {
        printf("Invalid id: %d", id_to_edit);
        return -1;
    }

    while(head != NULL && head->id != id_to_edit)
        head = head->next;

    if(head == NULL)
    {
        printf("No item found with an id of %d\n", id_to_edit);
        return -1;
    }
    
    printf("This item will be edited\n");
    print_item(head);

    char* new_name = get_string(NAME_SIZE, "Enter new name");
    
    char choice = get_char("Are you sure you want to edit this item?");

    if(choice == 'n' || choice == 'N')
    {
        free(new_name);
        return -1;
    }
    
    free(head->name);
    head->name = new_name;

    printf("Item successfully edited\n");

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

