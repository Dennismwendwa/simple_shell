
#include "main.h"

/**
  * _kalloc - allocates memory
  * @s:- size to allocate
  * Return:- Always 0
  */

void *_kalloc(unsigned int s)
{
	unsigned int j;
	char *k;

	if (s == 0)
	{
		return (NULL);
	}

	k = malloc(s);
	if (k == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < s; j++)
		k[j] = '\0';

	return (k);
}

/**
  * filling_array - fills arrys with const bytes
  * @size:- size of number
  * @num:- the number
  * @kim:- pointer
  * Return:- Always 0
  */

void *filling_array(void *y, int num, unsigned int size)
{
	unsigned int j = 0;
	char *z = y;

	while (j < size)
	{
		*z = num;
		z++;
		j++;
	}


	return (y);
}


/**
  * memorycpy - function that cpy memeory
  * @source:- source pointer
  * @dst:- where to cpy to
  * @k:- the size to cpy
  * Return:- Always 0
  */

char *memorycpy(char *dst, char *source, unsigned int k)
{
	unsigned int j = 0;

	for (; j < k; j++)
	{
		dst[j] = source[j];
	}

	return (dst);
}


/**
  * freeing_all - function that frees pointer
  * @kbq:- ptr array
  * @linne:- ptr
  * Return:- Always 0
  */

void freeing_all(char **kbq, char *linne)
{
	free(kbq);
	free(linne);
	kbq = NULL;
	linne = NULL;
}

/**
  * _reallocc - function that realoctes memory
  * @newersize:- the new pointer size
  * @oldersize:- the older pointer size
  * @pointer:- pointer to memory
  * Return:- Always 0
  */

void *_reallocc(void *pointer, unsigned int oldersize, unsigned int newersize)
{
	void *outcome;

	if (newersize == oldersize)
	{
		return (pointer);
	}

	if (newersize == 0 && pointer)
	{
		free(pointer);
		return (NULL);
	}
	outcome = malloc(newersize);
	if (outcome == NULL)
	{
		return (NULL);
	}
	if (pointer == NULL)
	{
		filling_array(outcome, '\0', newersize);
		free(pointer);
	}
	else
	{
		memorycpy(outcome, pointer, oldersize);
		free(pointer);
	}
	return (outcome);
}
