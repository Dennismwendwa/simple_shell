
#include "main.h"

/**
  * exit_buildin - exits with stat
  * @inputi:- single user input
  * @argv:- commands caunt
  * @k:- number of commands executed
  * @cmd:- commands to exicute
  * Return:- Always 0
  */

void exit_buildin(char **cmd, char *inputi, char **argv, int k)
{
	int m = 0;
	int stat;

	if (cmd[1] == NULL)
	{
		free(inputi);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	while (cmd[1][m])
	{
		if (own_isalpha(cmd[1][m++]) != 0)
		{
			print_error(argv, k, cmd);
			break;
		}
		else
		{
			stat = own_atoi(cmd[1]);
			free(inputi);
			free(cmd);
			exit(stat);
		}
	}
}

/**
  * disen - shows variables of env
  * @cmd:- command to exucute
  * @prt:- command excuted last status
  * Return:- Always 0
  */

int disen(__attribute__((unused)) char **cmd, __attribute__((unused)) int prt)
{
	int length;
	size_t l = 0;

	for (; environ[l] != NULL; l++)
	{
		length = own_strlen(environ[l]);
		write(1, environ[l], length);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}



/**
  * dir_change - function to change directory
  * @cmd:- command to excute
  * @print:- command performed last
  * Return:- Always 0
  */


int dir_change(char **cmd, __attribute__((unused))int print)
{
	char cwd[PATH_MAXIMUM];
	int number = -1;

	if (cmd[1] == NULL)
	{
		number = chdir(getenv("HOME"));
	}
	else if (own_strcmp(cmd[1], "-") == 0)
	{
		number = chdir(getenv("OLDPWD"));
	}
	else
	{
		number = chdir(cmd[1]);
	}




	if (number == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (number != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}

	return (0);
}

/**
  * bul_echo - phundle echo
  * @cmd:- command to excute
  * @start:- command status
  * Return:- Always 0
  */

int bul_echo(char **cmd, int start)
{
	unsigned int pid_num = getppid();
	char *pathh;

	if (own_strncmp(cmd[1], "$$", 2) == 0)
	{
		numberin_print(pid_num);
		PRINTING("\n");
	}
	else if (own_strncmp(cmd[1], "$?", 2) == 0)
	{
		num_print(start);
		PRINTING("\n");
	}
	else if (own_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		pathh = _getenv("PATH");
		PRINTING(pathh);
		PRINTING("\n");
		free(pathh);
	}
	else
	{
		return (echo_print(cmd));
	}

	return (1);
}


/**
  * help_display - shows hlp for bullin
  * @print:- status of command exucuted last
  * @cmd:- command to execute
  * Return:- Always 0
  */

int help_display(char **cmd, __attribute__((unused)) int print)
{
	char k;
	int kl;
	int ky;
	int red = 1;

	kl = open(cmd[1], O_RDONLY);
	if (kl < 0)
	{
		perror("Error");
		return (0);
	}


	while (red > 0)
	{
		red = read(kl, &k, 1);
		ky = write(STDOUT_FILENO, &k, red);

		if (ky < 0)
			return (-1);
	}

	_putchar('\n');

	return (0);
}
