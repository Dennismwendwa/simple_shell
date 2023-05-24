#include "main.h"

/**
  * exec_mngr - contrals cmd to the right flow
  * @argv:- commandline angs(cmd)
  * Return:- Alwyas 0
  */

int exec_mngr(char *const *argv)
{
	int r_val;

	r_val = exe_builtn(argv);

	if (r_val == 0)
		return (0);

	if (err_msg == 2)
	{
		r_val = (exe_extern(argv));
		if (r_val == 0)
			return (0);
	}

	return (-1);
}

/**
  * exe_builtn - finds the comnds to exec
  * @argv:- table
  * Return:- Always 0
  */

int exe_builtn(char *const *argv)
{
	built_in fps[] = {
		{"exit", bltin_exit},
		{"env", bltin_env},
		{"cd", dir_change},
		{NULL, NULL}
	};

	int j;

	int (*built_in_fp)(char *const *argv);

	for (j = 0; fps[j].cmd; j++)
		if ((own_strcmp(argv[0], fps[j].cmd)) == 0)
		{
			built_in_fp = fps[j].fp;
			if ((built_in_fp(argv)) == 0)
			{
				return (0);
			}
		err_msg = 3;
		return (-1);
		}
	err_msg = 2;
	return (-1);
}

/**
  * exe_extern - find external commands
  * @argv:- table
  * Return:- Always 0
  */

int exe_extern(char *const *argv)
{
	char **pat = NULL;
	int status, j;
	pid_t pid;

	if (checking_path(argv))
	{
		pat = (char **)alloc_mngr((char *)pat, (sizeof(char *) * 2));
		pat[0] = alloc_mngr(pat[0], (sizeof(char) * (own_strlen(argv[0]) + 1)));
		own_strncpy(pat[0], argv[0], own_strlen(argv[0]));
		pat[1] = NULL;
	}
	else
		pat = getting_pathh(argv);
	for (j = 0; pat[j]; j++)
	{
		if (access(pat[j], (R_OK | X_OK)) == 0)
		{
			switch ((pid = fork()))
			{
				case -1:
					return (-1);

				case 0:
					execve(pat[j], argv, environ);
					err_msg = 1;

					exit(EXIT_FAILURE);
				default:
					if ((waitpid(pid, &status, 0)) == -1)
						return (-1);
					else
						return (0);
			}
		}
	}
	err_msg = 2;
	return (-1);
}
