#include "shell.h"

void execute_command(char **args) {
    if (access(args[0], X_OK) == 0) {
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0) {
            /* Child process */
            if (execve(args[0], args, NULL) == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("Error forking");
        } else {
            /* Parent process */
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    } else {
        perror("Command not found");
    }
}

