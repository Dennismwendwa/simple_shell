#include "main.h"

/**
 * print_error - prints the error
 * @cnt: The error count
 * @cmd: command execute
 * @arg_v: the program
 * Return: Void
 */

void print_error(char **arg_v, int cnt, char **cmd)
{
	char *er = own_itoa(cnt);

	PRINTING(arg_v[0]);
	PRINTING(": ");
	PRINTING(er);
	PRINTING(": ");
	PRINTING(cmd[0]);
	PRINTING(": Illegal number: ");
	PRINTING(cmd[1]);
	PRINTING("\n");
	free(er);
}

/**
 * bltin_env - print process environment
 * @argv: command table
 *
 * Return: 0 on Success, -1 on Failure
 */
int bltin_env(char *const *argv)
{
	size_t length, row;

	if (!argv[1])
	{
		for (row = 0; environ[row]; row++)
		{
			length = own_strlen(environ[row]);

			if ((write(STDOUT_FILENO, environ[row], length)) == -1)
				return (-1);
			if ((write(STDOUT_FILENO, "\n", 1)) == -1)
				return (-1);
		}
	}
	else
	{
		errno = ENOENT;
		return (-1);
	}
	return (0);
}
