#include "main.h"

/**
 * file_treat - For parsing check command fork excute and wait
 * @buffer: Line in the file
 * @fp: A file descriptor
 * @arg_v: Name of program
 * @count: Error counter
 * Return: Execute line
 */

/*void file_treat(char *buffer, int count, FILE *fp, char **arg_v)
{
	int str = 0;
	char **cmd;

	cmd = cmd_parse(buffer);
	if (own_strncmp(cmd[0], "exit", 4) == 0)
	{
		file_exit_bul(cmd, buffer, fp);
	}
	else if (builtin_check(cmd) == 0)
	{
		str = builtin_handle(cmd, str);
		free(cmd);
	}
	else
	{
		str = cmd_check(cmd, buffer, count, arg_v);
		free(cmd);
	}
}*/

/**
 * file_exit_bul - Exit shell case of file
 * @buffer: Line in the file
 * @fil_d: file descriptor
 * @cmd: command parse
 * Return: A file line case exit
 */

/*void file_exit_bul(char **cmd, char *buffer, FILE *fil_d)
{
	int j = 0;
	int statu;

	if (cmd[1] == NULL)
	{
		free(buffer);
		free(cmd);
		fclose(fil_d);
		exit(errno);
	}
	while (cmd[1][j])
	{
		if (own_isalpha(cmd[1][j++]) < 0)
		{
			perror("illegal number");
		}
	}
	statu = own_atoi(cmd[1]);
	free(buffer);
	free(cmd);
	fclose(fil_d);
	exit(statu);
}*/

/**
 * file_read - Read Command From File
 * @filename:Filename
 * @arg_v:Program file Name
 * Return: -1 or  0
 */
/*
void file_read(char *filename, char **arg_v)
{
	int count = 0;
	size_t length = 0;
	FILE *fp;
	char *buffer = NULL;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &length, fp)) != -1)
	{
		count++;
		file_treat(buffer, count, fp, arg_v);
	}
	if (buffer)
		free(buffer);
	fclose(fp);
	exit(0);
}*/
