#include "shell.h"

/**
 * handle_error - Display an error message
 * @message: The error message to display
 */
void handle_error(char *message)
{
    fprintf(stderr, "%s\n", message);
}

/**
 * handle_eof - Handle end-of-file condition
 */
void handle_eof(void)
{
    printf("\n");  /* Print a newline on end-of-file */
    exit(EXIT_SUCCESS);
}

