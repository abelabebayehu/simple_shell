#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv, char **envp)
{
	char *input;

	(void)argc;

	while (1)
	{
		display_prompt();
		input = read_input();
		if (input == NULL)
		{
			free(input);
			break;
		}

		/* Trim newline character */
		input[strcspn(input, "\n")] = '\0';

		if (execute_command(input, envp) == -1)
		{
			/* Error handling */
			fprintf(stderr, "%s: %s: No such file or directory\n", argv[0], input);
		}

		free(input);
	}

	return (0);
}
