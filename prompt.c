#include "shell.h"

void display_prompt(void)
{
    char hostname[1024];
    char cwd[1024];
    char prompt[2048];

    if (gethostname(hostname, sizeof(hostname)) == -1)
    {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    sprintf(prompt, "%s:%s$ ", hostname, cwd);
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

