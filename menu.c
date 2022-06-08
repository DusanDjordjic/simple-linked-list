#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "menu.h"
#include "utils.h"

#define BUF_SIZE 2

char* get_input();

char menu()
{
    char* buffer; 
    printf("Please select an option\n");
    printf("(1) Print list\n");
    printf("(2) Add an item\n");
    printf("(3) Remove an item\n");
    printf("(4) Edit an item\n");
    printf("(0) Exit\n");
    printf("Your choice: ");

    // Change BUF_SIZE as you need
    buffer = get_input();

    // Copy first char to new variable so it does not get lost
    char user_choice = buffer[0];

    free(buffer);

    return user_choice;
}

char* get_input()
{

    char* buffer = (char*)malloc(sizeof(char) * BUF_SIZE); 
    char i = 0;

    // Get up to BUF_SIZE - 1 beacuse we want to set last byte no '\0' anyway
    while((buffer[i] = getchar()) != '\n' || i < BUF_SIZE - 1)
        i++;

    // Flush the input stream to get rid of garbage data left over in input buffer
    clear_ibuffer();

    // Set last bit to \0
    buffer[BUF_SIZE - 1] = '\0';
    return buffer;
}

