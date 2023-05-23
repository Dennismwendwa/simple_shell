#include "main.h"

/**
 * main - entry point of the shell, checks interactivity
 * @arg_c: arg count
 * @arg_v: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(int arg_c, char *arg_v[])
{
	char *buffer = NULL;
	int i, num_tokens = 0, cmdcount = 1, shell_inter;
	size_t bufsize = 0;

	signal(SIGINT, SIG_IGN);
	shell_inter = isatty(STDIN_FILENO);
	if (shell_inter == 0 && arg_c == 1)
	{
		while (getline(&buffer, &bufsize, stdin) > 0)
		{
			num_tokens = numcount(buffer);
			parsing(buffer, num_tokens, arg_v, cmdcount);
			buffer = NULL;
		}
		free(buffer);
		return (0);
	}
	while (shell_inter)
	{
		write(1, "($) ", 4);
		num_tokens = 0;
		i = getline(&buffer, &bufsize, stdin);
		if (i < 0)
		{
			free(buffer);
			write(1, "\n", 1);
			break;
		}
		num_tokens = numcount(buffer);
		parsing(buffer, num_tokens, arg_v, cmdcount);
		cmdcount++;
		buffer = NULL;
	}
	return (0);
}
