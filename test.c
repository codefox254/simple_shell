#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

void display_prompt(void) {
    printf("simple_shell$ ");
    fflush(stdout);
}

int main(void) {
    char input[MAX_INPUT_LENGTH];
    pid_t pid;

    while (1) {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            /* Handle end of file condition (Ctrl+D) */
            printf("\n");
            break;
        }

        /* Remove newline character from the input */
        input[strcspn(input, "\n")] = '\0';

        /* Fork a child process */
        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            /* Child process */
            execlp(input, input, NULL);

            /* If execlp fails, print an error message and exit */
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

