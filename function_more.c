
#include "main.h"

/**
  * own_strcpy - function that copies string
  * @det:- destection
  * @sorce:- from the loction
  * Return:- Always 0
  */

char *own_strcpy(char *det, char *sorce)
{
	int k = 0;

	while (sorce[k])
	{
		det[k] = sorce[k];
		k++;
	}

	det[k] = '\0';

	return (det);
}


/**
  * own_strchr - function that search for chr=ars
  * @k:- the char to besearched
  * @h:- the string to search
  * Return:- Always 0
  */

char *own_strchr(char *h, char k)
{
	do {

		if (*h == k)
		{
			break;
		}
	} while (*h++);

	return (h);
}


/**
  * own_strcat - function that joins string
  * @det:- dest
  * @sorce:- to location
  * Return:- Always 0
  */

char *own_strcat(char *det, char *sorce)
{
	char *f = det;

	while (*det != '\0')
	{
		det++;

	}

	while (*sorce != '\0')
	{
		*det = *sorce;
		det++;
		sorce++;

	}


	*det = '\0';
	return (f);

}

/**
  * own_strncmp - function that compare string
  * @a:- string 1
  * @b:- string 2
  * @k:- number of chars to compare
  * Return:- Always 0
  */

int own_strncmp(const char *a, const char *b, size_t k)
{
	size_t j;

	if (a == NULL)
	{
		return (-1);
	}

	for (j = 0; j < k && b[j]; j++)
	{
		if (a[j] != b[j])
			return (1);
	}

	return (0);

}


/**
  * own_strdup - function that duplicates string
  * @string:- the string to dumplicate
  * Return:- Always 0
  */

char *own_strdup(char *string)
{
	size_t length;
	size_t j;
	char *string2;

	length = own_strlen(string);
	string2 = malloc(sizeof(char) * (length + 1));

	if (!string2)
	{
		return (NULL);
	}

	for (j = 0; j <= length; j++)
	{
		string2[j] = string[j];

	}

	return (string2);

}
