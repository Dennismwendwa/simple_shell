#include "main.h"

/**
  * counting_digt - function that cnt dgts
  * @number:- number to count
  * Return:- Always 0
  */

size_t counting_digt(size_t number)
{
	size_t digitcount = 0;

	while (number != 0)
	{
		number /= 10;
		digitcount++;
	}

	return (digitcount);
}

/**
  * own_itoa - function that changes num to str
  * @ba:- string base
  * @buff:- arry of str
  * @num:- input
  * Return:- Always 0
  */

char *own_itoa(size_t num, char *buff, int ba)
{
	int sign = 1;
	int idx = 0;
	size_t rem = 0;

	if (num == 0)
	{
		buff[idx++] = '0';
		buff[idx] = '\0';
	}
	while (num)
	{
		rem = num % ba;
		buff[idx++] = '0' + rem;
		num /= ba;
	}
	if (sign < 0)
	{
		buff[idx++] = '-';
	}

	buff[idx] = '\0';
	return (reverse_string(buff));
}


















































































/**
 * echo_print - echo command execution
 * @cmd: Command parsed
 * Return: Success 0, Fail -1
 */
int echo_print(char **cmd) /* not in use */
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
	/* not in use */
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
		PRINTING(err);
		free(err);
		PRINTING(" ");
		PRINTING(buffer);
	}
	if (buffer)
		free(buffer);
	fclose(fp);
	return (0);
}
