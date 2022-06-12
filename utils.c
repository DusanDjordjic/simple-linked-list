#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void clear_ibuffer()
{
    while(getchar() != '\n');
} 

char* get_string(int size, const char* prompt)
{

    printf("%s (max %d): ", prompt, size);

    char* buffer = (char*)malloc(sizeof(char) * (size + 1));
    if(buffer == NULL)
    {
        perror("Error happend while allocating memory for new name");
        exit(1);
    }
    int i = 0;
    while((buffer[i] = getchar()) != '\n' && i < size)
            i++;

    // If user just pressed enter
    // Return invalid option
    if(buffer[0] == '\n')
    {
        buffer[0] = '-';
        buffer[1] = '\0';
        printf("\n");
        return buffer;
    }
        
    if(i == size && buffer[i] != '\n')
        clear_ibuffer();
    else if(i < size)
        buffer = (char*)realloc(buffer, sizeof(char) * (i + 1));

    buffer[i] = '\0';
    printf("\n");
    return buffer;
}

int get_int(char* prompt)
{
    int num = -1;
    printf("%s", prompt);
    scanf("%d", &num);
 
    // Clear input buffer or leading white space and '\n'
    clear_ibuffer();

    printf("\n");
    return num;
}

char get_char(char* prompt)
{
    char choice;
    printf("%s (Y/n): ", prompt);

    // If user entered something we want to clear ibuffer
    if(choice != '\n')
        clear_ibuffer();
    else 
        choice = 'Y';

    printf("\n");
    return choice;
}
