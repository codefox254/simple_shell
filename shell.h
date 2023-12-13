#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

void handle_builtin(char *command, char *args[]);
void handle_input_redirection(char *command, char *input_file);
void handle_output_redirection(char *command, char *output_file);
void execute_command(char *command, char *args[]);
void display_prompt(void);
char *read_command(void);
void trim_whitespace(char *str);
void tokenize_string(char *input, char *tokens[]);
void free_tokens(char *tokens[]);
void free_memory(void);
void handle_cd(char *args[]);
void handle_exit(char *args[]);

#endif /* SHELL_H */

