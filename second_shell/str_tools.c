
#include "main.h"

/**
  * own_strdup - function that duplicates str
  * @string:- the str
  * Return:- Always 0
  */


char *own_strdup(char *string)
{
	char *car;
	unsigned int j, s;

	if (string == NULL)
	{
		return (NULL);
	}

	for (s = 0; *(string + s) != '\0'; s++)
	{
		;
	}

	car = malloc((s + 1) * sizeof(char));

	if (car == NULL)
	{
		return (NULL);
	}

	for (j = 0; string[j] != '\0'; j++)
	{
		car[j] = string[j];
	}

	car[j] = '\0';
	return (car);
}

/**
  * number_count - function that counts toks
  * @lin:- user input
  * Return:- Always 0
  */

int number_count(char *lin)
{
	int j;
	int chk = 1;
	int toks = 0;

	for (j = 0; lin[j]; j++)
	{
		if (lin[j] == ' ' || lin[j] == 10 || lin[j] == '\t')
			chk = 1;

		else if (chk == 1)
		{
			chk = 0;
			++toks;
		}
	}

	return (toks);

}





/**
  * own_strcat - function that joins str
  * @dst:- string one
  * @source:- string two
  * Return:- Always 0
  */


char *own_strcat(char *dst, char *source)
{
	int lenone = 0;
	int lentwo = 0;
	int j;


	while (*(source + lenone) != '\0')
	{
		lenone++;
	}

	while (*(dst + lentwo) != '\0')
	{
		lentwo++;
	}

	for (j = 0; j <= lenone; j++)
	{
		*(dst + (lentwo + j)) = *(source + j);
	}

	return (dst);
}


/**
  * own_strncmp - function to comprare strings
  * @length:- the length of str your are compering
  * @stringtwo:- userinput
  * @stringone:- userinput
  * Return:- always 0
  *
  */

int own_strncmp(char *stringone, char *stringtwo, int length)
{
	for (; *stringone && *stringtwo && length >= 0; length--)
	{
		if (*stringone == *stringtwo)
		{
			stringone++;
			stringtwo++;
		}

		else
		{
			return (-1);
		}
	}

	return (0);
}


/**
  * own_strcmp - function that compares string
  * @stringtwo:- user input
  * @stringone:- user input
  * Return:- Always 0
  */

int own_strcmp(char *stringone, char *stringtwo)
{
	while (*stringone || *stringtwo)
	{
		if (*stringone == *stringtwo)
		{
			stringone++;
			stringtwo++;
		}

		else
		{
			return (-1);
		}
	}
	return (0);
}
