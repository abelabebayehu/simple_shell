#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);

		if (nread == -1) /* Handle EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		/* Remove newline character */
		line[nread - 1] = '\0';

		/* Prepare arguments for execve */
		argv[0] = line;
		argv[1] = NULL;

		pid = fork();
		if (pid == -1) /* Fork failed */
		{
			perror("Error:");
			continue;
		}
		if (pid == 0) /* Child process */
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else /* Parent process */
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
