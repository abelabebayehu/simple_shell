#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 * @envp: The environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command, char **envp)
{
	char *argv[2];
	pid_t pid;
	int status;

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	if (pid == 0)
	{
		/* Child process */
		if (execve(command, argv, envp) == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
	}

	return (0);
}
