#include "shell.h"

extern char **environ;

/**
 * exit_shell - Exit the shell.
 */
void exit_shell(void) {
    printf("Exiting shell\n");
    exit(EXIT_SUCCESS);
}

/**
 * env_shell - Print the current environment.
 */
void env_shell(void) {
    char **env = environ;

    while (*env) {
        printf("%s\n", *env++);
    }
}

int main(void) {
    char *input;
    char **args;

    while (1) {
        display_prompt("($) "); /* Pass a string literal as an argument */
        input = read_input();
        args = parse_input(input);

        if (args[0] != NULL) {
            if (strcmp(args[0], "exit") == 0) {
                exit_shell();
            } else if (strcmp(args[0], "env") == 0) {
                env_shell();
            } else {
                execute_command(args);
            }
        }

        free(input);
        free(args);
    }
}

