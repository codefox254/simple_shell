#include "shell.h"

// Function to trim leading and trailing whitespaces from a string
void trim_whitespace(char *str)
{
    int start = 0, end = strlen(str) - 1;

    // Trim leading whitespaces
    while (isspace((unsigned char)str[start]))
    {
        start++;
    }

    // All whitespaces?
    if (start == end + 1)
    {
        str[0] = '\0';
        return;
    }

    // Trim trailing whitespaces
    while (isspace((unsigned char)str[end]))
    {
        end--;
    }

    // Shift characters to the beginning of the string
    int i, j = 0;
    for (i = start; i <= end; i++, j++)
    {
        str[j] = str[i];
    }

    // Null-terminate the trimmed string
    str[j] = '\0';
}

