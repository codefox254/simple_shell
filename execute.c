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
        // Child process

        // Check for built-in commands
        if (strcmp(command, "list") == 0)
        {
            list_files();
            exit(EXIT_SUCCESS);
        }

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
        // Parent process
        waitpid(child_pid, &status, 0);
    }

    return 0;
}

/**
 * list_files - List files in the current directory
 */
void list_files(void)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG) // Display regular files only
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

