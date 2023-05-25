#include "main.h"

/**
  * cd_Home - change home directory
  * Return:- Always 0
  */
int cd_Home(void)
{
	char *dirtag = NULL;

	dirtag = tar_get("HOME=");

	if (dirtag)
	{
		if (chdir(dirtag) == 0)
		{
			set_OLDPWD();
			set_PWD(dirtag);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}


/**
  * dir_change - function to change directory
  * @argv:- command to excute
  * Return:- Always 0
  */
int dir_change(char *const *argv)
{
	if (argv[1] == NULL || !(own_strcmp(argv[1], "~")))
	{
		if (cd_Home())
			return (-1);
	}
	else if (!(own_strcmp(argv[1], ".")))
	{
		if (cd_cur())
			return (-1);
	}
	else if (!(own_strcmp(argv[1], "..")))
	{
		if (parent_cd())
			return (-1);
	}
	else if (!(own_strcmp(argv[1], "-")))
	{
		if (cd_prev())
			return (-1);
	}
	else if ((!(own_strncmp(argv[1], "~", 1)) && (argv[1][1] != '\0')))
	{
		if (cd_user(argv[1]))
			return (-1);
	}
	else
	{
		if (cd_arg(argv[1]))
			return (-1);
	}
	return (0);
}
/**
 * cd_cur - change home directory
 * Return: 0 on Success, -1 on Failure
 */

int cd_cur(void)
{
	char *dirtag = NULL;

	dirtag = tar_get("PWD=");

	if (dirtag)
	{
		int chdir_result = chdir(dirtag);

		if (chdir_result == 0)
		{
			set_OLDPWD();
			set_PWD(dirtag);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}
/**
  * cd_prev - move to previous directory
 * Return: 0 on Success, 1 on Failure
 */
int cd_prev(void)
{
	char *tar_dir = NULL;

	tar_dir = tar_get("OLDPWD=");
	if (tar_dir)
	{
		if (chdir(tar_dir) == 0)
		{
			set_OLDPWD();
			set_PWD(tar_dir);
			write(STDOUT_FILENO, tar_dir, own_strlen(tar_dir));
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);

}

/**
 * parent_cd - move to parent directory
 * Return: 0 on Success, 1 on Failure
 */
int parent_cd(void)
{
	char *dirtar = NULL;
	size_t i;

	dirtar = tar_get("PWD=");
	if (dirtar)
	{
		for (i = own_strlen(dirtar); dirtar[i] != '/';)
			i--;

		for (; dirtar[i]; i++)
			dirtar[i] = '\0';

		if (chdir(dirtar) == 0)
		{
			set_OLDPWD();
			set_PWD(dirtar);
			return (0);
		}
	}
	return (-1);
}
