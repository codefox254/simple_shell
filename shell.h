#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

/**
 * struct Shell - Struct to hold shell information.
 * @prompt: Function pointer to display the shell prompt.
 * @read_input: Function pointer to read user input.
 * @parse_input: Function pointer to parse user input.
 * @execute_command: Function pointer to execute a command.
 */
typedef struct Shell {
    void (*prompt)();
    char *(*read_input)();
    char **(*parse_input)(char *input);
    void (*execute_command)(char **args);
    void (*exit_shell)();
    void (*env_shell)();
} Shell;

/* Function declarations */
void display_prompt();
char *read_input();
char **parse_input(char *input);
void execute_command(char **args);
void exit_shell();
void env_shell();

#endif /* SHELL_H */

