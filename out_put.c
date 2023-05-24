#include "main.h"

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
