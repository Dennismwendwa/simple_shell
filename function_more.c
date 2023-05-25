
#include "main.h"

/**
  * own_strncpy - function that copy string
  * @destination:- new location
  * @source:- string
  * @count:- bytes to copy
  * Return:- Always 0
  */

char *own_strncpy(char *destination, const char *source, size_t count)
{
	size_t index = 0;

	while (index < count)
	{
		if (source[index] == '\0')
		{
			break;
		}
		destination[index] = source[index];
		index++;
	}

	destination[index] = '\0';

	while (index < count)
	{
		destination[index] = '\0';
		index++;
	}

	return (destination);
}


/**
  * own_strlen - function that return len
  * @string:- first string
  * Return:- Always 0
  */


size_t own_strlen(char *string)
{
	size_t length = 0;

	if (string)
		while (string[length] != '\0')
			length++;

	return (length);
}



/**
  * own_strcmp - function that compare two strings
  * @string1:- input one
  * @string2:- input two
  * Return:- Always 0
  */

int own_strcmp(char *string1, char *string2)
{
	int index = 0;


	while (string1[index] != '\0')
	{
		if (string1[index] < string2[index])
		{
			return (string1[index] - string2[index]);
		}

		if (string1[index] > string2[index])
		{
			return (string1[index] - string2[index]);
		}
		index++;
	}

	if (string2[index] != '\0')
	{
		return (string1[index] - string2[index]);
	}

	return (0);
}





/**
  * own_strncmp - function that compare string
  * @string1:- first string
  * @string2: second string.
  * @num:- number of chars to compare
  * Return:- Always 0
  */

int own_strncmp(char *string1, char *string2, size_t num)
{
	size_t k = 0;

	while (k < num && string1[k] != '\0')
	{
		if (string1[k] < string2[k])
		{
			return (string1[k] - string2[k]);
		}

		if (string1[k] > string2[k])
		{
			return (string1[k] - string2[k]);
		}

	k++;
	}
if (k < num && string2[k] != '\0')
{
	return (string1[k] - string2[k]);
}
return (0);
}



/**
  * own_strcat - function that joins string
  * @destination:- string two
  * @source: string one
  * Return:- Always 0
  */

char *own_strcat(char *destination, char *source)
{
	int source_index = 0;
	int destination_index = 0;


	for (; destination[destination_index] != '\0';)
	{
		destination_index++;
	}

	for (; source[source_index] != '\0';)
	{
		destination[destination_index] = source[source_index];
		source_index++;
		destination_index++;
	}


	destination[destination_index] = '\0';
	return (destination);
}









