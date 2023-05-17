
#include "main.h"

/**
  * get_line - function that reads commandline inputs
  * Return:- Always 0
  */

char *get_line()
{
	char k = 0;
	int buffersize = BUFFERSIZE, readd;
	char *buffer = malloc(buffersize);
	int j;

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (j = 0; k != EOF && k != '\n'; k++)
	{
		fflush(stdin);
		readd = read(STDIN_FILENO, &k, 1);

		if (readd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[j] = k;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}

		if (j >= buffersize)
		{
			buffer = _reallocc(buffer, buffersize, buffersize + 1);
			if (buffer == NULL)
				return (NULL);
		}
	}

	buffer[j] = '\0';
	hundle_hashtag(buffer);
	return (buffer);
}

/**
  * hundle_hashtag - function that deletes chars after #
  * @buffer:- commandline input
  * Return:- Always 0
  */

void hundle_hashtag(char *buffer)
{
	int j = 0;

	for (; buffer[j] != '\0'; j++)
	{
		if (buffer[j] == '#')
		{
			buffer[j] = '\0';
			break;
		}
	}
}
