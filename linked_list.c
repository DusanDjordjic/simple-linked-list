#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "utils.h"
#include "defs.h"
#include "item.h"

void print_list(Node* head)
{
    if(head == NULL)
    {
        printf("No items added yet.\n");
        return;
    }

    while(head != NULL)
    {
        item_print(head->item);
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
    
    item_print(head->item);
}

int add_item(Node** phead)
{
     
    Node* node = (Node*)malloc(sizeof(Node));
    Item* new_item = (Item*)malloc(sizeof(Item));

    if(node == NULL || new_item == NULL)
    {
        perror("Error while allocating memory for new node\n");
        free(node);
        free(new_item);
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
        next_id = tmphead->item->id + 1;
    }

    new_item->id = next_id;
    new_item->name = get_string(NAME_SIZE, "Enter new name", &new_item->name_len);

    node->item = new_item;
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
    

    if(tmphead->item->id == id_to_remove)
    {
        *phead = tmphead->next;
        printf("Removed item with an id of %d\n", id_to_remove);
        free(tmphead->item->name);
        free(tmphead->item);
        free(tmphead);
        return -1;
    }
    
    while(tmphead != NULL && tmphead->item->id != id_to_remove)
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
    free(tmphead->item->name);
    free(tmphead->item);
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

    while(head != NULL && head->item->id != id_to_edit)
        head = head->next;

    if(head == NULL)
    {
        printf("No item found with an id of %d\n", id_to_edit);
        return -1;
    }
    
    printf("This item will be edited\n");
    print_item(head);
    int new_name_size = 0;
    char* new_name = get_string(NAME_SIZE, "Enter new name", &new_name_size);
    
    char choice = get_char("Are you sure you want to edit this item?");

    if(choice == 'n' || choice == 'N')
    {
        free(new_name);
        return -1;
    }
    
    free(head->item->name);
    head->item->name = new_name;
    head->item->name_len = new_name_size;

    printf("Item successfully edited\n");

    return 0;
}

int reverse_list(Node** phead)
{
    if(*phead == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    if((*phead)->next == NULL)
    {
        printf("List has only one item.\n");
        return -1;
    }

    Node* slow = NULL;
    Node* fast = *phead;

    while(fast != NULL)
    {
        Node* tmp = fast;
        fast = fast->next;
        tmp->next = slow;
        slow = tmp;
    }
    print_list(slow);
    *phead = slow;

    return 0;
}
void free_list(Node** phead)
{
    Node* tmp;
    Node* head = *phead;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp->item->name);
        free(tmp->item);
        free(tmp);
    }
}

void load_list(const char* filename, Node** phead)
{
    FILE* data_file = fopen(filename, "rb");

    if(data_file == NULL)
    {
        printf("%s file not found\n", filename);
        *phead = NULL;
        return;
    }

    if(*phead != NULL)
    {
        printf("Free list before load\n");
        free_list(phead);
        *phead = NULL;
    }

    int read_bytes = 1;
    while(read_bytes > 0)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        Item* new_item = (Item*)malloc(sizeof(Item));

        read_bytes = fread(&(new_item->id), sizeof(int), 1, data_file);
        if(read_bytes <= 0)
        {
            free(new_node);
            free(new_item);
            break;
        }

        fread(&(new_item->name_len), sizeof(int), 1, data_file);

        new_item->name = (char*)malloc(sizeof(char) * new_item->name_len);
        fread(new_item->name, sizeof(char) * new_item->name_len, 1, data_file);

        new_node->item = new_item;
        new_node->next = *phead;
        *phead = new_node;
    }
    reverse_list(phead);
}

void save_list(Node* head, const char* filename)
{
    FILE* data_file = fopen(filename, "wb");

    if(data_file == NULL)
    {
        printf("Could not open %s file for writing\n", filename);
        fclose(data_file);
        return;
    }

    int byte_counter = 0;
    while(head != NULL)
    {
        fwrite(&(head->item->id), sizeof(int), 1, data_file);
        fwrite(&(head->item->name_len), sizeof(int), 1, data_file);
        fwrite(head->item->name, sizeof(char) * head->item->name_len, 1, data_file);
        byte_counter += sizeof(int) * 2 + sizeof(char) * head->item->name_len; 
        head = head->next;
    }
    fclose(data_file);

    printf("Wrote %d bytes\n", byte_counter);
}
