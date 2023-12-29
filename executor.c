#include "shell.h"

/**
 * execute_command - Execute the given command.
 * @args: An array of strings containing the command and its arguments.
 */
void execute_command(char **args)
{
	if (access(args[0], X_OK) == 0)
	{
		pid_t pid, wpid;
		int status;

		pid = fork();
		if (pid == 0)
		{
			/* Child process */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Error forking");
		}
		else
		{
			/* Parent process */
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED);
				printf("Waiting for child process %d\n", wpid); /* Use the wpid variable */
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
	{
		perror("Command not found");
	}
}

