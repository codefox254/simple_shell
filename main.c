#include "shell.h"

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t line_len;
    char *command = NULL;  /* Move the declaration to the top of the block */
    char *args[MAX_ARGS];

    while (1) {
        printf("hsh$ ");
        line_len = getline(&line, &len, stdin);
        if (line_len == -1) {
            perror("hsh");
            exit(EXIT_FAILURE);
        }

        line[strcspn(line, "\n")] = '\0';  /* Remove trailing newline */

        parse_input(line, &command, args);

        if (command != NULL) {
            if (strcmp(command, "exit") == 0) {
                free(line);
                free(command);  /* Free allocated memory for command */
                exit(EXIT_SUCCESS);
            } else if (strcmp(command, "cd") == 0) {
                change_directory(args[0]);
            } else {
                execute_command(command, args);
            }
        }

        free(command);  /* Free allocated memory for command */
    }

    free(line);
    return 0;
}

