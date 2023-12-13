#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_INPUT 1024

void execute_command(char *command, char *args[]);
char *read_command(void);
void handle_builtin(char *command, char *args[]);
void handle_input_redirection(char *command, char *input_file);
void handle_output_redirection(char *command, char *output_file);
void trim_whitespace(char *str);
void handle_sigint(int signo);
void handle_sigtstp(int signo);
void set_environment_variable(char *name, char *value);
void tokenize_string(char *input, char *tokens[]);
void free_tokens(char *tokens[]);
void print_error(const char *msg);
void change_directory(const char *path);
void display_prompt(void);

#endif /* SHELL_H */

