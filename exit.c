#include "main.h"

int is_num(char let);
int own_atoi(char *status);

/**
 * bltin_exit - Exits the shell
 * @argv: The status to exit shell with
 *
 * Return: Either exits the shell or returns EXIT_FAILURE
 */
int bltin_exit(char *const *argv)
{
	int ans;

	if (argv[1] == NULL)
	{
		free_memlst(&mem_head);
		free_static_memlst(&static_mem_head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ans = own_atoi(argv[1]);

		switch (ans)
		{
			case (-1):
				return (EXIT_FAILURE);
			default:
				free_memlst(&mem_head);
				free_static_memlst(&static_mem_head);
				exit(ans);
		}
	}
}

/**
 * is_num - Checks if a char is a number
 * @let: The char to check
 * Return: Always 1 on success or 0 on failure
 */
int is_num(char let)
{
	if (let >= '0' && let <= '9')
		return (1);

	return (0);
}

/**
 * own_atoi - Converts string into a number
 * @status: The string to convert
 * Return: Always the status as an int or -1
 */
int own_atoi(char *status)
{
	int ans = 0;
	int i = 0;

	if (status[i] == '-')
		return (-1);

	for (i = 0; status[i] != '\0'; i++)
	{
		if (is_num(status[i]))
		{
			ans = ans * 10 + status[i] - '0';
		}
		else
			return (-1);
	}
	if (ans > 2147483647)
	{
		return (-1);
	}
	else
		return (ans);
}
