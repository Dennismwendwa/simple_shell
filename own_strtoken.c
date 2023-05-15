
#include "main.h"

/**
  * delim_check - function to check the delimiter to use
  * @g:- the char to check
  * @string:- the string we will be checking
  * Return:- Always 0
  */


unsigned int delim_check(char g, const char *string)
{
	unsigned int l = 0;

	for (; string[l] != '\0'; l++)
	{
		if (g == string[l])
		{
			return (1);
		}
	}

	return (0);
}


/**
  * own_strtok - function tokezes str
  * @string:- str to tokeniz
  * @sep:- delimiter to use
  * Return:- Always 0
  */

char *own_strtok(char *string, const char *sep)
{
	unsigned int k;
	static char *numbr, *tip;

	if (string != NULL)
	{
		numbr = string;
	}
	tip = numbr;

	if (tip == NULL)
		return (NULL);
	for (k = 0; tip[k] != '\0'; k++)
	{
		if (delim_check(tip[k], sep) == 0)
			break;
	}
	if (numbr[k] == '\0' || numbr[k] == '#')
	{
		numbr = NULL;
		return (NULL);
	}
	tip = numbr + 1;
	numbr = tip;
	for (k = 0; numbr[k] != '\0'; k++)
	{
		if (delim_check(numbr[k], sep) == 1)
			break;
	}
	if (numbr[k] == '\0')
		numbr = NULL;
	else
	{
		numbr[k] = '\0';
		numbr = numbr + k + 1;
		if (*numbr == '\0')
		{
			numbr = NULL;
		}
	}
	return (tip);
}
