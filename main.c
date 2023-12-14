#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_input();

        if (command == NULL)
        {
            handle_eof();
            continue;
        }

        execute_command(command);

        free(command);  /* Free the allocated memory for the command */
    }

    return 0;
}

