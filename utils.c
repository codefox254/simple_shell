#include "shell.h"

void display_prompt() {
    printf("($) ");
}

char *read_input() {
    char *input = NULL;
    size_t bufsize = 0;

    printf("Enter command: ");
    getline(&input, &bufsize, stdin);

    return input;
}

