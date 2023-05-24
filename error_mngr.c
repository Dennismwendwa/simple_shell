#include "main.h"

char *three_case(char *errcus, char **tok_ary);

/**
 * printing_error - error print
 * @argv: Contains the name of the shell
 * @tok_arry: Contains needed tokens for error message
 * @loop_cnt: Current iteration of shell loop
 */
void printing_error(size_t loop_cnt, char *argv, char **tok_arry)
{
	char *err_tag = NULL, *loop_num = NULL, *err_cus = NULL;
	size_t err_cus_len, err_tag_len;
	size_t digit_amnt = counting_digt(loop_cnt);
	size_t tok1_len = own_strlen(tok_arry[0]), tok2_len = own_strlen(tok_arry[1]);
	size_t argv_len = own_strlen(argv);
	size_t total_alloc = argv_len + digit_amnt + tok1_len + tok2_len + 6;

	switch (err_msg)
	{
		case (2):
			err_cus = alloc_mngr(err_cus, (sizeof(char) * 12));
			err_cus = ": not found\0";
			break;
		case (3):
			err_cus = three_case(err_cus, tok_arry);
			if (err_cus == NULL)
				return;
			break;
		default:
			perror(argv);
			return;
	}

	loop_num = alloc_mngr(loop_num, (sizeof(char) * (digit_amnt + 1)));
	own_itoa(loop_cnt, loop_num, 10);

	err_cus_len = own_strlen(err_cus);
	total_alloc += err_cus_len;

	err_tag = alloc_mngr(err_tag, sizeof(char) * total_alloc);

	own_strncpy(err_tag, argv, argv_len);
	own_strcat(err_tag, ": ");
	own_strcat(err_tag, loop_num);
	own_strcat(err_tag, ": ");
	own_strcat(err_tag, tok_arry[0]);
	own_strcat(err_tag, err_cus);
	if (err_msg == 3)
		own_strcat(err_tag, tok_arry[1]);
	own_strcat(err_tag, "\n");

	err_tag_len = own_strlen(err_tag);

	write(STDERR_FILENO, err_tag, err_tag_len);
}

/**
 * three_case - Creates or prints error message
 * @errcus: Where the custom error message is saved to
 * @tok_ary: Contains needed tokens for customized message
 * Return: Either NULL or pointer to custom error message
 */
char *three_case(char *errcus, char **tok_ary)
{
	size_t tok1_len = own_strlen(tok_array[0]);
	size_t tok2_len = own_strlen(tok_array[1]);

	if (tok1_len == 4)
	{
		errcus = alloc_mngr(errcus, (sizeof(char) * 19));
		errcus = ": Illegal number: \0";
		return (errcus);
	}
	else if (tok1_len == 2)
	{
		errcus = alloc_mngr(errcus, (sizeof(char) * 15));
		errcus = ": can't cd to \0";
		return (errcus);
	}

	errcus = alloc_mngr(errcus, sizeof(char) * tok1_len + tok2_len + 5);
	own_strncpy(errcus, tok_array[0], tok1_len);
	own_strcat(errcus, ": '");
	own_strcat(errcus, tok_array[1]);
	own_strcat(errcus, "'");

	errno = ENOENT;
	perror(errcus);
	return (NULL);
}
