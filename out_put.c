#include "main.h"

/**
 * printing_error - prints the error
 * @cnt: The error count
 * @cmd: command execute
 * @arg_v: the program
 * Return: Void
 */

void printing_error(char **arg_v, int cnt, char **cmd)
{
	char *er = own_itoa(cnt);

	PRINTING(arg_v[0]);
	PRINTING(": ");
	PRINTING(err);
	PRINTING(": ");
	PRINTING(cmd[0]);
	PRINTING(": Illegal number: ");
	PRINTING(cmd[1]);
	PRINTING("\n");
	free(err);
}
