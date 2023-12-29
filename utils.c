#include "shell.h"

void display_prompt(const char *prompt) { /* Use const char * for prompt */
    printf("%s", prompt); /* Use %s instead of ($) */
}

char *read_input(void) { /* Use void as the parameter list */
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t nread;

    printf("Enter command: ");
    nread = getline(&input, &bufsize, stdin); /* Store the return value of getline */
    if (nread == -1) { /* Check for errors */
        perror("getline error");
        exit(EXIT_FAILURE);
    }

    free(input); /* Use free to deallocate the memory */
    return input;
}

