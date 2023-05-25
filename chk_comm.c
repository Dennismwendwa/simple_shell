#include "shell.h"

/**
 * check_command_exists - check command
 * @command: for command
 * Return: 0 success
 */
int check_command_exists(const char *command)
{
	char *path;
	char *dir, *full_path;
	struct stat st;

	path = getenv("PATH");
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
		{
			free(full_path);
			return (1);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (0);
}
