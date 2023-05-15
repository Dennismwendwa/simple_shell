#include "main.h"

/**
 * echo_print - echo command execution
 * @cmd: Command parsed
 * Return: Success 0, Fail -1
 */
int echo_print(char **cmd)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * disp_hist - Display History Of User Input Simple Shell
 * @cm:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */
int disp_hist(__attribute__((unused))char **cm, __attribute__((unused))int s)
{
	int count = 0;
	char *err;
	size_t length = 0;
	FILE *fp;
	char *buffer = NULL;
	char *filename = ".shell_history";

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&buffer, &length, fp)) != -1)
	{
		count++;
		err = own_itoa(count);
		PRINTER(err);
		free(err);
		PRINTER(" ");
		PRINTER(buffer);
	}
	if (buffer)
		free(line);
	fclose(fp);
	return (0);
}
