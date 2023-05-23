
#include "main.h"

/**
  * mine_free - function that free pointers
  * @lin:- pointer to free
  * @nwlin:- pointer to free
  * @arry:- pointer to free
  * @arrs:- pointer to free
  * Return:- Always 0
  */

void mine_free(char *lin, char **arrs, char *nwlin, char **arry)
{
	int j = 0;

	if (arrs != NULL)
	{
		while (arrs[j] != NULL)
		{
			free(arrs[j]);
			j++;
		}

		free(arrs);
	}

	if (nwlin != NULL)
	{
		free(nwlin);
	}
	if (lin != NULL)
	{
		free(lin);
	}
	if (arry != NULL)
	{
		free(arry);
	}
}



/**
  * parsing - function that generates toks
  * @lin:- user input
  * @number_tok:- toks amount
  * @coutcmd:- count of input
  * @argv:- argvs array
  * Return:- Always 0
  */

int parsing(char *lin, int number_tok, char **argv, int coutcmd)
{
	int val_ex = 0, j = 0, bult;
	char *m = NULL, **arrs = NULL, **arry_tok = NULL, *nwlin = NULL;
	char *delim = " \t\r\n\f\v";

	arry_tok = malloc(sizeof(char *) * number_tok);

	nwlin = own_strdup(lin);
	m = _strtok(nwlin, delim);

	if (m == NULL)
	{
		mine_free(lin, arrs, nwlin, arry_tok);
		return (0);

	}
	for (; m != NULL; m = _strtok(NULL, delim))
	{
		arry_tok[j++] = m;
	}
	arrs = malloc(sizeof(char *) * (number_tok + 1));

	for (j = 0; j < number_tok; j++)
	{
		arrs[j] = own_strdup(arry_tok[j]);
	}
	arrs[j] = NULL;
	bult = checking_bltin(lin, arrs, nwlin, arry_tok);
	if (bult == 0)
	{
		val_ex = exe(lin, arrs, nwlin, arry_tok, argv, coutcmd);
	}
	mine_free(lin, arrs, nwlin, arry_tok);
	return (val_ex);
}
