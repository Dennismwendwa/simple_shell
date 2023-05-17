
#include "main.h"

/**
  * _getenv - finds the variable of env
  * @nickname:- name of the env
  * Return:- Always 0
  */


char *_getenv(char *nickname)
{
	int a, b, c;
	char *volum;
	size_t number, value1;


	number = own_strlen(nickname);
	for (a = 0; environ[a]; a++)
	{
		if (own_strncmp(nickname, environ[a], number) == 0)
		{
			value1 = own_strlen(environ[a]) - number;
			volum = malloc(sizeof(char) * value1);


			if (!volum)
			{
				free(volum);
				perror("alloc failed");
				return (NULL);
			}

			c = 0;
			for (b = number + 1; environ[a][b]; b++, c++)
				volum[c] = environ[a][b];

			volum[c] = '\0';
			return (volum);
		}


	}
	return (NULL);
}

/**
  * pathh_cmd - search for commands
  * @input:- command to excute
  * Return:- Always 0
  */


int pathh_cmd(char **input)
{
	struct stat buff;
	char *way;
	char *volum;
	char *input_pathh;

	way = _getenv("PATH");
	volum = own_strtok(way, ":");

	while (volum != NULL)
	{
		input_pathh = building(*input, volum);
		if (stat(input_pathh, &buff) == 0)
		{
			*input = own_strdup(input_pathh);
			free(input_pathh);
			free(way);
			return (0);
		}

		free(input_pathh);
		volum = own_strtok(NULL, ":");

	}

	free(way);

	return (1);
}

/**
  * building - dunction that buld commnds
  * @words:- commands to perform
  * @volum:- dir with commands to excute
  * Return:- Always 0
  */


char *building(char *words, char *volum)
{
	size_t length;
	char *kbq;

	length = own_strlen(volum) + own_strlen(words) + 2;

	kbq = malloc(sizeof(char) * length);

	if (kbq == NULL)
		return (NULL);

	memset(kbq, 0, length);

	kbq = own_strcat(kbq, volum);
	kbq = own_strcat(kbq, "/");
	kbq = own_strcat(kbq, words);

	return (kbq);
}
