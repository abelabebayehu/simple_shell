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
	(void)argc;
	(void)argv;
	(void)envp;

	display_prompt();

	return (0);
}
