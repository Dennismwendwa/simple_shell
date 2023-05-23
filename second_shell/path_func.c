#include "main.h"

/**
 * find_path - find PATH in environ
 * @toks: token to pass along to PATH
 * Return: 0 for success
 */
int find_path(char **toks)
{
	char *p = NULL;
	char *pth = NULL;
	int j = 0, ownpath;

	for (j = 0; environ[j] != NULL; j++)
	{
		if (own_strncmp("PATH=", environ[j], 5) == 0)
		{
			pth = own_strdup(environ[j]);
			strtok(pth, "=");
			p = strtok(NULL, "=");
			ownpath = path_search(p, toks);
			break;
		}
	}
	free(pth);
	return (ownpath);
}

/**
 * own_strcpy - copies str from src to dest
 * @src: source string
 * @dest: destination string
 * Return: pointer to destination string
 */
char *own_strcpy(char *dest, char *src)
{
	int length = 0;
	int j;

	while (*(src + len) != '\0')
	{
		length++;
	}
	for (j = 0; j <= legth; j++)
	{
		*(dest + j) = *(src + j);
	}
	return (dest);
}

/**
 * path_exe - function to access PATH
 * @p: directory in PATH to access
 * @toks: array of tokens to check
 */
void path_exe(char *p, char **toks)
{
	int status, len, len2;
	pid_t child;
	char *newp = NULL;

	for (len = 0; *(p + len) != '\0'; len++)
		;
	for (len2 = 0; toks[0][len2] != '\0'; len2++)
		;
	newp = malloc(sizeof(char) * (len + len2 + 2));
	own_strcpy(newp, p);
	own_strcat(newp, "/");
	own_strcat(newp, toks[0]);
	newp[(len + len2 + 1)] = '\0';

	child = fork();

	if (child == 0)
	{
		if (access(newp, X_OK) == 0)
		{
			execve(newp, toks, environ);
		}
	}
	else
	{
		while (waitpid(-1, &status, 0) != child)
			;
	}
	if (status == 0)
		errno = 0;
	free(newp);
}

/**
 * path_search - function to search PATH
 * @p: part of PATH to search
 * @toks: array of tokens
 * Return: 0 for success
 */
int path_search(char *p, char **toks)
{
	int reached = 0, onpath = -1;
	struct dirent *de;

	p = strtok(p, ":");
	while (p != NULL && reached != 1)
	{
		DIR *dr = opendir(p);

		if (dr == NULL)
		{
			return (0);
		}
		while ((de = readdir(dr)) != NULL)
		{
			if (own_strcmp(de->d_name, toks[0]) == 0)
			{
				path_exe(p, toks);
				onpath = 0;
				reached = 1;
				break;
			}
		}
		closedir(dr);
		if (reached == 0)
			p = strtok(NULL, ":");
	}
	return (onpath);
}
