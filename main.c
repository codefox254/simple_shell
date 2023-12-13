#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_command();
        if (command == NULL)
            break;

        execute_command(command);

        free_command(command);
    }

    printf("\n");
    return (0);
}

