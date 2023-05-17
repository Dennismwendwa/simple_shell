#include "main.h"

/**
 * cmd_parse - To parse line buffer
 * @buffer: User input
 * Return: Array of char parsed
 */

char **cmd_parse(char *buffer)
{
	int j = 0;
	int buf_size = BUFFERSIZE;
	char **toks;
	char *tok;

	if (buffer == NULL)
		return (NULL);
	toks = malloc(sizeof(char *) * buf_size);
	if (!toks)
	{
		perror("hsh");
		return (NULL);
	}

	tok = own_strtok(buffer, "\n ");
	while (tok)
	{
		toks[j] = tok;
		tok = own_strtok(NULL, "\n ");
		j++;
	}
	toks[j] = NULL;
	return (toks);
}
