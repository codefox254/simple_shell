#include "shell.h"

// Function to handle the "cd" built-in command
void handle_cd(char *args[])
{
    if (args[1] == NULL)
    {
        // Change to the home directory if no arguments are provided
        char *home = getenv("HOME");
        if (home == NULL)
        {
            print_error("cd");
        }
        else
        {
            change_directory(home);
        }
    }
    else
    {
        change_directory(args[1]);
    }
}

// Function to handle the "echo" built-in command
void handle_echo(char *args[])
{
    for (int i = 1; args[i] != NULL; i++)
    {
        write(STDOUT_FILENO, args[i], strlen(args[i]));
        write(STDOUT_FILENO, " ", 1);
    }
    write(STDOUT_FILENO, "\n", 1);
}

// Function to handle the "exit" built-in command
void handle_exit(char *args[])
{
    // Perform any cleanup or additional actions before exiting if needed
    exit(EXIT_SUCCESS);
}

// Add more built-in functions as needed

// Function to handle built-in commands
void handle_builtin(char *command, char *args[])
{
    if (strcmp(command, "cd") == 0)
    {
        handle_cd(args);
    }
    else if (strcmp(command, "echo") == 0)
    {
        handle_echo(args);
    }
    else if (strcmp(command, "exit") == 0)
    {
        handle_exit(args);
    }
    // Add more built-in commands here
    else
    {
        // Handle unrecognized built-in commands or indicate that the command is not built-in
        fprintf(stderr, "Unknown built-in command: %s\n", command);
    }
}

