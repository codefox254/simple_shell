#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void free_command(char *command);

#endif /* SHELL_H */

