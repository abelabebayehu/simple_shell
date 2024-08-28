#include "shell.h"

/**
 * builtin_exit - Handles the built-in exit command.
 * @info: Structure containing potential arguments, used to maintain
 *        a consistent function prototype.
 * Return: Exits with a specified status if an exit argument is provided.
 *         Returns (1) if the argument is not a valid number.
 *         Returns (-2) to indicate a valid exit command was found.
 *         Returns (0) if info.argv[0] is not "exit".
 */

int builtin_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}


