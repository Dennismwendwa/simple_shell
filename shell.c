#include "main.h"

/**
 * main - The shell program
 * @arg_cnt: The argument count
 * @arg_v: The argument value
 * Return: Exit value by status
 */

int main(__attribute__((unused)) int arg_cnt, char **arg_v)
{
	int str = 0, count = 0;
	char *buffer, **cmd;

	if (arg_v[1] != NULL)
		file_read(arg_v[1], arg_v);
	signal(SIGINT, signal_handle);

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			fun_prompt();
		buffer = get_line();
		if (buffer[0] == '\0')
		{
			continue;
		}
		buf_history(buffer);
		cmd = cmd_parse(buffer);
		if (own_strcmp(cmd[0], "exit") == 0)
		{
			exit_buildin(cmd, buffer, arg_v, count);
		}
		else if (builtin_check(cmd) == 0)
		{
			str = builtin_handle(cmd, str);
			freeing_all(cmd, buffer);
			continue;
		}
		else
		{
			str = cmd_check(cmd, buffer, count, arg_v);
		}
		freeing_all(cmd, buffer);
	}
	return (1);
}

/**
 * env_create - To make array of enviroment variable
 * @envi: Array of enviro variables
 * Return: void
 */
void env_create(char **envi)
{
	int j = 0;

	while (environ[j])
	{
		envi[j] = own_strdup(environ[j]);
		j++;
	}
	envi[j] = NULL;
}

/**
 * builtin_check - for checking builtins
 * @cmd: For commands to check
 *
 * Return: 0 Success, -1 Fail
 */
int builtin_check(char **cmd)
{
	build_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"history", NULL},
		{"echo", NULL},
		{NULL, NULL}
	};
	int j = 0;

	if (*cmd == NULL)
	{
		if (own_strcmp(cmd[0], (fun + j)->command) == 0)
			return (0);
		j++;
	}
	return (-1);
}
