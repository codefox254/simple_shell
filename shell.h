#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h> // For directory listing

void display_prompt(void);
char *read_input(void);
int execute_command(char *command);
void handle_error(char *message);
void handle_eof(void);
void list_files(void); // New function for listing files

#endif /* SHELL_H */

