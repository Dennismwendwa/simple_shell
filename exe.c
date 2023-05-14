#include "main.h"

/**
 * signal_handle - It handles ^C
 * @sig_n: To get signal
 * Return: void
 */
void signal_handle(int sig_n)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}

/**
 * builtin_handle - For handling builtin commands
 * @ere: stat for last execute
 * @cmd: parsed command
 * Return: 0 success, -1 Fail (Return: Execute builtin)
 */
int builtin_handle(char **cmd, int ere)
{
	built_t bil[] = {
		{"cd", dir_change},
		{"env", display_env},
		{"echo", bul_echo},
		{"help", help_display},
		{"history", dis_history},
		{NULL, NULL}
	};
	int j = 0;

	while ((bil + j)->command)
	{
		if (own_strcmp(cmd[0], (bil + j)->command) == 0)
		{
			return ((bil + j)->fun(cmd, ere));
		}
		j++;
	}
	return (-1);
}

/**
 * cmd_check - Execute fork, excute, wait
 * @buffer: the user input
 * @tc: shell execution time case of command not found
 * @cmd: parsed comm
 * @arg_v: argument name
 * Return: 1 case comm Null -1, wrong 0
 */
int cmd_check(char *buffer, char **cmd, int tc, char **arg_v)
{
	pid_t pid;
	int status;

	if (*cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (own_strncmp(*cmd, "./", 2) != 0 && own_strncmp(*cmd, "/", 1) != 0)
		{
			cmd_path(cmd);
		}
		if (execve(*cmd, cmd, environ) == -1)
		{
			error_print(cmd[0], tc, arg_v);
			free(buffer);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
