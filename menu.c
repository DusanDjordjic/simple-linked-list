#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "menu.h"
#include "utils.h"
#include "defs.h"

char menu()
{
    char* buffer; 
    printf("\nPlease select an option\n");
    printf("(1) Load list\n");
    printf("(2) Print list\n");
    printf("(3) Add an item\n");
    printf("(4) Remove an item\n");
    printf("(5) Edit an item\n");
    printf("(0) Exit\n");

    // Change MENU_BUF_SIZE as you need
    buffer = get_string(MENU_BUF_SIZE, "Your choice" );

    // Copy first char to new variable so it does not get lost
    char user_choice = buffer[0];

    free(buffer);
    return user_choice;
}

