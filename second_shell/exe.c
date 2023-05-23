#include "main.h"

/**
 * exe - functin=on that executes new processes
 * @buffer: user input
 * @dpl: line duplicate
 * @ar: array to be handled by execve
 * @argv: arguments
 * @tok: Tokens to check
 * @fcnt: number of commands that have failed
 * Return: 0 for success
 */
int exe(char *buffer, char **ar, char *dpl, char **tok, char **argv, int fcnt)
{
	int status, ownpath = -1;
	pid_t child;
	struct stat *statbuf;

	statbuf = malloc(sizeof(struct stat));
	if (stat(ar[0], statbuf) == -1)
	{
		ownpath = find_path(ar);
		if (ownpath == 0)
		{
			free(statbuf);
			return (0);
		}
	}
	child = fork();
	if (child == 0)
	{
		if (execve(ar[0], ar, environ) == -1)
		{
			print_f("%s: %d: %s: not found\n", argv[0], fcnt, ar[0]);
			free(statbuf);
			mem_free(buffer, ar, dpl, tok);
			_exit(-1);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
	free(statbuf);
	if (status == 0)
		errno = 0;
	if (status == 512)
		errno = 2;
	if (status == 65280)
		errno = 127;
	return (0);
}
