#include "main.h"

/**
 * envi_free - to free environment array val
 * @envi: Environment variable
 * Return: Void
 */
void envi_free(char **envi)
{
	int j = 0;

	while (envi[j])
	{
		free(envi[j]);
		j++;
	}
}

/**
 * buf_history - Fill File By User Input
 * @buffer: User Input
 * Return: -1 Fail 0 Succes
 */

int buf_history(char *buffer)
{
	int length = 0;
	char *file_n = ".shell_history";
	ssize_t fd, w;

	if (!file_n)
		return (-1);
	fd = open(file_n, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
	{
		while (buffer[length])
			length++;
		w = write(fd, buffer, length);
		if (w < 0)
			return (-1);
	}
	return (1);
}
