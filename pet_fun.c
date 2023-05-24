
#include "main.h"

/**
 * tar_get - copy target path from environ
 * @var_name: name of target env variable
 * Return: target path on Success, NULL on Failure
 */
char *tar_get(char *var_name)
{
	char *path = NULL;
	size_t i = 0;
	size_t path_len = 0;
	size_t name_len = own_strlen(var_name);

	for (; environ[i]; i++)
	{
		if ((own_strncmp(var_name, environ[i], name_len)) == 0)
		{
			path_len = (own_strlen(environ[i]) - name_len);
			path = alloc_mngr(path, (sizeof(char) * (path_len + 1)));
			if (!path)
			{
				return (NULL);
			}
			own_strncpy(path, &environ[i][name_len], path_len);
			return (path);
		}
	}
	errno = ENOENT;
	return (NULL);
}

/**
 * cd_user - move to user home
 * @argv: User name
 * Return: 0 on Success, 1 on Failure
 */
int cd_user(char *argv)
{
	char *userdir = NULL;
	size_t user_len = _strlen(argv);

	userdir = alloc_mngr(userdir, (sizeof(char) * (6 + user_len)));
	if (!userdir)
		return (-1);

	own_strncpy(userdir, "/home/", 6);
	own_strcat(userdir, &argv[1]);

	if (chdir(userdir) == 0)
	{
		set_OLDPWD();
		set_PWD(userdir);
		return (0);
	}
	errno = ENOENT;
	return (-1);
}


/**
 * set_PWD - set path value of environ var PWD
 * @val: desired value of variable
 * Return:- Always 0
 */
int set_PWD(char *val)
{
	size_t val_len, i = 0;
	char *update = NULL;
	char *name = "PWD=";
	size_t n_len = 4;

	val_len = own_strlen(val);
	for (; environ[i]; i++)
	{
		if ((own_strncmp(name, environ[i], n_len)) == 0)
		{
			environ[i] = own_realloc(update, (sizeof(char) * (n_len + val_len + 1)));
			if (!environ[i])
				return (-1);

			add_memnode(&static_mem_head, environ[i]);

			own_strncpy(environ[i], name, n_len);
			own_strcat(environ[i], val);

			if (environ[i][n_len + val_len - 1] == '/')
				environ[i][n_len + val_len - 1] = '\0';
			return (0);
		}
	}
	errno = ENOENT;
	return (-1);
}

/**
 * set_OLDPWD - set path value of environ var OLDPWD
 *
 * Return: 0 on Success, 1 on Failure
 */
int set_OLDPWD(void)
{
	char *update = NULL;
	char *pwd = NULL;
	char *owd_ref = "OLDPWD=";
	char *pwd_ref = "PWD=";
	size_t i;
	size_t pwd_len = 0;

	for (i = 0; environ[i]; i++)
	{
		if ((own_strncmp(pwd_ref, environ[i], 4)) == 0)
			pwd = &environ[i][4];
	}
	if (!pwd)
		return (-1);

	pwd_len = own_strlen(pwd);
	for (i = 0; environ[i]; i++)
	{
		if ((_strncmp(owd_ref, environ[i], 7)) == 0)
		{
			environ[i] = own_realloc(update, (sizeof(char) * (7 + pwd_len + 1)));
			if (!environ[i])
				return (-1);
			add_memnode(&static_mem_head, environ[i]);
			own_strncpy(environ[i], owd_ref, 7);
			own_strcat(environ[i], pwd);

			return (0);
		}
	}
	errno = ENOENT;
	return (-1);
}

/**
 * cd_arg - move to given path
 * @argv: The directory to go to
 * Return: 0 on Success, 1 on Failure
 */
int cd_arg(char *argv)
{
	char *dirtar = NULL;
	char *path = NULL;
	size_t len = 0;

	if (chdir(argv) == 0)
	{
		if (checking_path(&argv))
		{
			set_OLDPWD();
			set_PWD(argv);
			return (0);
		}
		else
		{
			dirtar = tar_get("PWD=");
			len = (own_strlen(dirtar) + own_strlen(argv));
			path = alloc_mngr(path, (sizeof(char) * (len + 2)));
			if (!path)
			{
				return (-1);
			}
			own_strncpy(path, dirtar, own_strlen(dirtar));
			own_strcat(path, "/");
			own_strcat(path, argv);

			set_OLDPWD();
			set_PWD(path);
			return (0);
		}
	}
	errno = ENOENT;
	return (-1);
}
