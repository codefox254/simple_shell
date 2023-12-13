#include "shell.h"

/**
 * free_command - Free the allocated memory for a command
 * @command: The command to be freed
 */
void free_command(char *command)
{
    if (command != NULL)
        free(command);
}

