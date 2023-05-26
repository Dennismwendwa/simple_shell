
#include "main.h"

void printing_alias(_aliast *als);
void setting_alias(char *namevar, char *vlue);
int byshell_alis(char **args, char __attribute__((__unused__)) **back);

/**
  * replacing_alias - function that replas alias
  * @args:- double ptr to args
  * Return:- Always 0
  */


char **replacing_alias(char **args)
{
	_aliast *pmt;

	int j;
	char *nwvlue;

	if (own_strcmp(args[0], "alias") == 0)
		return (args);

	for (j = 0; args[j]; j++)
	{
		pmt = aliases;
		while (pmt)
		{
			if (own_strcmp(args[j], pmt->name) == 0)
			{
				nwvlue = malloc(sizeof(char) * (own_strlen(pmt->value) + 1));

				if (!nwvlue)
				{
					freeing_args(args, args);
					return (NULL);
				}

				own_strcpy(nwvlue, pmt->value);
				free(args[j]);
				args[j] = nwvlue;
				j--;
				break;
			}

			pmt = pmt->next;
		}
	}

	return (args);
}


/**
  * printing_alias - function that prnts all als in disc
  * @als:- als ptr
  * Return:- Always 0
  */

void printing_alias(_aliast *als)
{
	char *str_als;
	int length;

	length = own_strlen(als->name) + own_strlen(als->value) + 4;

	str_als = malloc(sizeof(char) * (length + 1));


	if (!str_als)
		return;


	own_strcpy(str_als, als->name);
	own_strcat(str_als, "='");


	own_strcat(str_als, als->value);
	own_strcat(str_als, "'\n");

	write(STDOUT_FILENO, str_als, length);
	free(str_als);
}


/**
  * setting_alias - function that sets alises
  * @vlue:- alias name
  * @namevar:- alis value
  * Return:- Always 0
  */

void setting_alias(char *namevar, char *vlue)
{
	_aliast *pmt = aliases;
	int i, length, c;
	char *nwvlue;

	*vlue = '\0';
	vlue++;
	length = own_strlen(vlue) - own_strspn(vlue, "'\"");
	nwvlue = malloc(sizeof(char) * (length + 1));
	if (!nwvlue)
		return;

	for (i = 0; c = 0; vlue[i]; i++)
	{
		if (vlue[i] != '\'' && vlue[i] != '"')
			nwvlue[c++] = vlue[i];
	}
	nwvlue[c] = '\0';
	while (pmt)
	{
		if (own_strcmp(nwvlue, pmt->name) == 0)
		{
			free(pmt->vlue);
			pmt->vlue = nwvlue;
			break;
		}
		pmt = pmt->next;
	}
	if (!pmt)
	alias_add_end(&aliases, namevar, nwvlue);
}




/**
  * byshell_alis - function that print alises
  * @back:- pointer to argv
  * @args:- commandline agrs
  * Return:- Always 0
  */

int byshell_alis(char **args, char __attribute__((__unused__)) **back)
{
	_aliast *pmt = aliases;
	int j, let = 0;
	char *vlue;

	if (!args[0])
	{
		while (pmt)
		{
			printing_alias(pmt);
			pmt = pmt->next;
		}

		return (let);
	}
	for (j = 0; args[j]; j++)
	{
		pmt = aliases;
		vlue = own_strchr(args[j], '=');
		if (!vlue)
		{
			while (pmt)
			{
				if (own_strcmp(args[j], pmt->name) == 0)
				{
					printing_alias(pmt);
					break;
				}
				pmt = pmt->next;
			}
			if (!pmt)
				let = creating_error(args + j, 1);
		}
		else
			setting_alias(args[j], vlue);
	}
	return (let);
}

/**
  * freeing_args - function that frees args ptr
  * @bck:- ptr to args
  * @args:- commandline args
  * Return:- Always 0
  */

void freeing_args(char **args, char **bck)
{
	size_t j;

	for (j = 0; args[j] || args[j + 1]; j++)
	{
		free(args[j];
	}

	free(bck);

}



