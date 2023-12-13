// execute.c
#include "shell.h"

/**
 * execute_command - Execute the given command
 * @command: The command to be executed
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        char *argv[] = {command, NULL};
        if (execve(command, argv, NULL) == -1)
        {
            perror("execve");
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

