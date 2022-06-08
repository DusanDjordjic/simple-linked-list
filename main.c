#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main()
{
    char users_choice;

    printf("*** Author: DusanDjordjic 2022. ***\n");
    printf("*** This software is free to use by anyone. ***\n\n"); 
    while(users_choice != 0)
    {
        users_choice = menu();
        switch(users_choice)
        {
            case '1':
                    printf("Option 1\n");
                    break;
            case '2':
                    printf("Option 2\n");
                    break;
            case '3':
                    printf("Option 3\n");
                    break;
            case '4':
                    printf("Option 4\n");
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
