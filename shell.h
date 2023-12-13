#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void free_command(char *command);

// New declarations for setenv.c
int set_environment_variable(char *variable, char *value);
int main_setenv(int argc, char *argv[]);

#endif /* SHELL_H */

