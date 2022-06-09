#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "menu.h"

int main()
{
    char users_choice;

    printf("***** Author: DusanDjordjic 2022. *******************\n");
    printf("***** This software is free to use by anyone. *****\n\n"); 
    
    // Loading list
    Node* head = load_list();
    
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
                    if(head == NULL)
                        head = add_item(1);
                    else
                        add_item_to_end(head);
                    break;
            case '4':
                    head = remove_item(head);
                    break;
            case '5':
                    break;
            case '0':
                    printf("Bye have a great time\n");
                    return 0;
            default:
                printf("\"%c\" is not a valid option\n\n", users_choice);
                break;
        }
    }
    return 0;
}
