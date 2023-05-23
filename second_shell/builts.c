
#include "main.h"

/**
  * checkbuilt - checks if token is command
  * @lin:- user input
  * @nwlin:- copy of nwlin
  * @arry_token:- commands to check
  * @arrs:- token know to exec
  * Return:- Always 0
  */

int checkbuilt(char *lin, char **arrs, char *nwlin, char **arry_token)
{
	int j = 0;

	if (own_strcmp(arrs[0], "exit") == 0)
	{
		_free(lin, arrs, nwlin, arry_token);
		_exit(errno);
	}

	if (own_strcmp(arrs[0], "env") == 0)
	{
		for (; environ[j] != NULL; j++)
		{
			_putts(environ[j]);
			write(1, "\n", 1);
		}

		return (2);
	}

	if (own_strcmp(arrs[0], "cd") == 0)
	{
		changing_dir(arrs);
		return (2);
	}

	return (0);
}

/**
  * changing_dir - function that changes dirs
  * @arrs:- dir to go to
  * Return:- Always 0
  */

void changing_dir(char **arrs)
{
	int j;

	char *valhome = NULL;
	char *hmee = NULL;

	if (arrs[1] == NULL)
	{
		for (j = 0; environ[j] != NULL; j++)
		{
			if (own_strncmp("HOME", environ[j], 5) == 0)
			{
				hmee = own_strdup(environ[j]);
				_strtok(hmee, "=");
				valhome = _strtok(NULL, "=");
				break;
			}

		}
	}

	else
	{
		valhome = arrs[1];
	}

	chdir(valhome);
	free(hmee);
}
