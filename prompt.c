#include "shell.h"

// Function to display the shell prompt
void display_prompt(void)
{
    char hostname[MAX_INPUT];
    char cwd[MAX_INPUT];

    // Get the hostname
    if (gethostname(hostname, sizeof(hostname)) == -1)
    {
        perror("Error getting hostname");
        exit(EXIT_FAILURE);
    }

    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("Error getting current working directory");
        exit(EXIT_FAILURE);
    }

    // Display the prompt in the format: [username@hostname:cwd]$
    printf("[%s@%s:%s]$ ", getenv("USER"), hostname, cwd);
    fflush(stdout);
}

