#include "shell.h"

char **parse_input(char *input) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token;
    int token_count = 0;

    token = strtok(input, " \t\n");
    while (token != NULL) {
        tokens[token_count++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }

    tokens[token_count] = NULL;  /* Mark the end of the array with NULL */
    return tokens;
}

