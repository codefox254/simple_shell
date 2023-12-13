#include "shell.h"

void handle_input_redirection(char *command, char *input_file)
{
    int fd = open(input_file, O_RDONLY);

    if (fd == -1)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Redirect standard input to the file
    if (dup2(fd, STDIN_FILENO) == -1)
    {
        perror("Error redirecting input");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void handle_output_redirection(char *command, char *output_file)
{
    int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1)
    {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Redirect standard output to the file
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("Error redirecting output");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

