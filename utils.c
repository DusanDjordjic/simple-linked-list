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

    if(i == size && buffer[i] != '\n')
        clear_ibuffer();
    else if(i < size)
        buffer = (char*)realloc(buffer, sizeof(char) * (i + 1));

    buffer[i] = '\0';
    printf("Buffer is %s\n", buffer);
    return buffer;
}

