#include "shell.h"

void parse_input(const char *line, char **command, char **args) {
    /* Initialize variables */
    int i = 0;
    char *token;
    char *mutable_line = strdup(line);

    /* Tokenize the line into command and arguments */
    *command = strtok(mutable_line, " \t\n");
    args[i++] = *command;

    /* Tokenize the remaining string into arguments */
    while ((token = strtok(NULL, " \t\n")) != NULL) {
        args[i++] = token;
    }

    /* Set the last argument to NULL to indicate the end of the argument list */
    args[i] = NULL;

    free(mutable_line);
}

void execute_command(char *command, char **args) {
    pid_t pid;
    int status;

    if ((pid = fork()) == 0) {
        /* Child process */
        if (execvp(command, args) == -1) {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        /* Fork error */
        perror("hsh");
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        waitpid(pid, &status, WUNTRACED);
        /* Note: wpid is not used, and we can directly wait for the child process */
    }
}

void change_directory(const char *path) {
    /* Change the current working directory using chdir */
    if (chdir(path) != 0) {
        perror("hsh");
        exit(EXIT_FAILURE);
    }
}

