#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
    printf("$ ");  /* Simple prompt */
}

/**
 * read_input - Read user input from the command line
 *
 * Return: The entered command or NULL on end-of-file
 */
char *read_input(void)
{
    char *input = NULL;
    size_t bufsize = 0;

    if (getline(&input, &bufsize, stdin) == -1)
    {
        return NULL;  /* Return NULL on end-of-file condition */
    }

    return input;
}

