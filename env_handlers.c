#include "shell.h"

// Function to set environment variable
void set_environment_variable(char *name, char *value)
{
    if (setenv(name, value, 1) == -1)
    {
        perror("Error setting environment variable");
    }
}

