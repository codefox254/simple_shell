#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* helpers.c */
void display_prompt(void);
char *read_input(void);

/* execute.c */
int execute_command(char *command);

/* error_handling.c */
void handle_error(char *message);
void handle_eof(void);

#endif /* SHELL_H */

