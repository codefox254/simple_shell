#include "shell.h"

// Signal handler for Ctrl+C (SIGINT)
void handle_sigint(int signo)
{
    if (signo == SIGINT)
    {
        write(STDOUT_FILENO, "\n#cisfun$ ", 10);
    }
}

// Signal handler for Ctrl+Z (SIGTSTP)
void handle_sigtstp(int signo)
{
    if (signo == SIGTSTP)
    {
        // Handle Ctrl+Z (suspend process)
        write(STDOUT_FILENO, "\n#cisfun$ ", 10);
    }
}

