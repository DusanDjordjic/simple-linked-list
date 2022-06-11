#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "menu.h"

int main()
{

    printf("\n\n***** Author: DusanDjordjic 2022. ****************************\n");
    printf("***** This software is free to use and modify by anyone. *****\n\n"); 
    
    Node* head = NULL; 
    char users_choice;

    while(users_choice != 0)
    {
        users_choice = menu();
        switch(users_choice)
        {
            case '1':
                    head = load_list();
                    break;
            case '2':
                    print_list(head);
                    break;
            case '3':
                    add_item(&head);
                    break;
            case '4':
                    remove_item(&head);
                    break;
            case '5':
                    edit_item(head);  
                    break;
            case '0':
                    printf("Bye have a great time.\n");
                    free_list(head);
                    return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}
