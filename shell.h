#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void handle_eof(void);
void change_directory(const char *path);
void parse_input(const char *input, char **command, char **args);
void execute_command(char *command, char **args);

#endif /* SHELL_H */

