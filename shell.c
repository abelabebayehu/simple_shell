#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	unsigned long len = 0;
	long nread;

	while (1)
	{
		prompt();

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Handle EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		/* Remove newline character */
		line[nread - 1] = '\0';

		if (line[0] != '\0') /* Ignore empty commands */
			execute_command(line);
	}

	free(line);
	return (0);
}

/**
 * prompt - Displays the shell prompt
 */
void prompt(void)
{
	printf("($) ");
}

/**
 * execute_command - Forks a child process to execute a command
 * @line: The command line to execute
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];

	argv[0] = line;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1) /* Fork failed */
	{
		perror("Error:");
		return;
	}
	if (pid == 0) /* Child process */
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(&status);
	}
}
