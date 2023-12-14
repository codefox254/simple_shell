#include "shell.h"

/**
 * execute_command - Execute the given command in a child process
 * @command: The command to execute
 *
 * Return: 0 on success, 1 on failure
 */
int execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1)
    {
        handle_error("Error creating child process");
        return 1;
    }

    if (child_pid == 0)
    {
        /* Child process */
        char **args = malloc(2 * sizeof(char *));
        if (args == NULL)
        {
            handle_error("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        args[0] = command;
        args[1] = NULL;

        if (execve(command, args, NULL) == -1)
        {
            handle_error("Command not found");
            free(args);
            exit(EXIT_FAILURE);
        }

        free(args);
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
    }

    return 0;
}

