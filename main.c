#include "shell.h"

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
    return 0;
}

