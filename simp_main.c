#include "shell.h"

/**
 * display_prompt - display prompt
 */
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * main - Main program
 * Return: success
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	char *args[BUFFER_SIZE];
	int i = 0;
	char *token;
	pid_t pid;

	while (1)
	{
		display_prompt();

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		token = strtok(buffer, " ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if (strcmp(args[0], "exit") == 0)
			break;

		if (!check_command_exists(args[0]))
		{
			printf("Command not found: %s\n", args[0]);
			continue;
		}

		/*if (access(args[0], X_OK) != 0)
		{
			printf("Command not found: %s\n", args[0]);
			continue;
		}*/
		pid = fork();

		if (pid < 0)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Execve error");
				exit(EXIT_FAILURE);
			}
			else
				wait(NULL);
		}
	}
	/*printf("\n");*/
	return (EXIT_SUCCESS);
}
