#include "shell.h"

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * read_input - Reads the input from the user
 *
 * Return: The input string or NULL on failure/EOF
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(0);  /* Handle Ctrl+D */
		}
		free(line);
		return (NULL);
	}

	return (line);
}
