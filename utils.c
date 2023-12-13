#include "shell.h"

// Function to tokenize a string
void tokenize_string(char *input, char *tokens[])
{
    char *token = strtok(input, " \t\n");
    int i = 0;

    while (token != NULL)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }

    tokens[i] = NULL;
}

// Function to free the memory allocated for tokens
void free_tokens(char *tokens[])
{
    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
}

// Function to print an error message
void print_error(const char *msg)
{
    perror(msg);
}

// Function to change the current working directory
void change_directory(const char *path)
{
    if (chdir(path) == -1)
    {
        print_error("cd");
    }
}

// Function to display the shell prompt
void display_prompt(void)
{
    char *prompt = "#cisfun$ ";
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

