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
	char target_dir[1024];
	int target_fd;
	ssize_t bytes_read;

	target_fd = open(".prevdir", O_RDONLY);
	if (target_fd == -1)
	{
		return (1);
	}

	bytes_read = read(target_fd, target_dir, sizeof(target_dir) - 1);
	if (bytes_read == -1)
	{
		close(target_fd);
		return (1);
	}

	target_dir[bytes_read] = '\0';
	if (chdir(target_dir) == 0)
	{
		set_OLDPWD();
		set_PWD(target_dir);
		write(STDOUT_FILENO, target_dir, own_strlen(target_dir));
		write(STDOUT_FILENO, "\n", 1);
		close(target_fd);
		return (0);
	}
	else
	{
		close(target_fd);
		return (1);
	}
}

/**
 * parent_cd - move to parent directory
 * Return: 0 on Success, 1 on Failure
 */
int parent_cd(void)
{
	char *dirtar = NULL;
	char *l_slash;
	size_t i;

	dirtar = tar_get("PWD=");
	if (dirtar)
	{
		l_slash = strrchr(dirtar, '/');
		if (l_slash)
		{
			for (i = strlen(dirtar); &dirtar[i] != l_slash; i--)
				dirtar[i] = '\0';

			if (chdir(dirtar) == 0)
			{
				set_OLDPWD();
				set_PWD(dirtar);
				return (0);
			}
		}
	}
	return (0);
}
