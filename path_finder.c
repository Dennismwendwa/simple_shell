
#include "main.h"

/**
  * getting_pathh - function foe getting paths
  * @argv:- commandline args
  * Return:- Always 0
  */

char **getting_pathh(char *const *argv)
{
	char *pat_pointer = NULL;
	char *reff = "PATH=";
	char **pat = NULL;
	size_t pat_count, env_i = 0, p_j;
	size_t pat_ctsiz;

	while (environ[env_i])
	{
		if (own_strncmp(reff, environ[env_i], 5) == 0)
		{
			pat_pointer = &environ[env_i][5];
			pat_count = counting_path(pat_pointer);
			pat = (char **)alloc_mngr((char *)pat, (sizeof(char *) * (pat_count + 1)));

			for (p_j = 0; p_j < pat_count; p_j++)
			{
				pat_ctsiz = (path_len(pat_pointer) + own_strlen(argv[0]) + 2);
				pat[p_j] = alloc_mngr(pat[p_j], (sizeof(char) * pat_ctsiz));

				own_strncpy(pat[p_j], pat_pointer, path_len(pat_pointer));
				own_strcat(pat[p_j], "/");
				own_strcat(pat[p_j], argv[0]);

				pat_pointer = (pat_pointer + (path_len(pat_pointer) + 1));
			}
			pat[p_j] = NULL;
			return (pat);
		}
		env_i++;
	}

	return (NULL);
}

/**
  * checking_path - function that checks path
  * @argv:- commandline args
  * Return:- Always 0
  */


size_t checking_path(char *const *argv)
{
	size_t j = 0;
	size_t path_t = 0;

	while (argv[0][j])
	{
		if (argv[0][j] == '/')
		{
			path_t = 1;
			break;
		}
		j++;
	}
	return (path_t);
}

/**
  * counting_path - function that return path cnt
  * @pat:- environ Path
  * Return:- Always 0
  */

size_t counting_path(char *pat)
{
	size_t j;
	size_t count_pat = 0;

	if (!pat)
	{
		return (0);
	}

	for (j = 0; pat[j]; j++)
	{
		if ((pat[j + 1] == ':' || pat[j + 1] == '\0'))
		{
			count_pat++;
		}
	}

	return (count_pat);
}

/**
  * length_path - function that is taks path
  * @pat_pointer:- ptr to path current
  * Return:- Always 0
  */

size_t length_path(char *pat_pointer)
{
	size_t j = 0;

	if (pat_pointer)
	{
		while (pat_pointer[j] != ':' && pat_pointer[j] != '\0')
		{
			j++;
		}
	}

	return (j);
}





















/**
  * _getenv - finds the variable of env
  * @nickname:- name of the env
  * Return:- Always 0
  */


char *_getenv(char *nickname) /* not in use */
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
