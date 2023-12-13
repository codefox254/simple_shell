#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
    printf("($) ");
}

/**
 * read_command - Read a command from the user
 *
 * Return: The entered command
 */
char *read_command(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    if (getline(&buffer, &bufsize, stdin) == -1)
    {
        free(buffer);
        return NULL;
    }

    return buffer;
}

