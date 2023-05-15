
#include "main.h"

/**
  * rev_arry - function that revrse arry
  * @ar:- the arry
  * @length:- size of the arry
  * Return:- Always 0
  */


void rev_arry(char *ar, int length)
{
	int k = 0;
	char tmp;

	for (; k < (length / 2); k++)
	{
		tmp = ar[k];
		ar[k] = ar[(length - 1) - k];
		ar[(length - 1) - k] = tmp;
	}
}

/**
  * own_intlen - returns length of thr number
  * @number:- the number to check length
  * Return:- Always 0
  */

int own_intlen(int number)
{
	int size = 0;

	while (number != 0)
	{
		size++;
		number /= 10;

	}

	return (size);
}



/**
  * own_itoa - function that changes ints to chars
  * @l:- the int to change
  * Return:- Always 0
  */

char *own_itoa(unsigned int l)
{
	char *m;
	int j = 0;
	int length = 0;

	length = own_intlen(l);
	m = malloc(length + 1);

	if (!m)
	{
		return (NULL);
	}

	*m = '\0';

	while (l / 10)
	{
		m[j] = (l % 10) + '0';
		l /= 10;
		j++;
	}

	m[j] = (l % 10) + '0';
	rev_arry(m, length);
	m[j + 1] = '\0';


	return (m);
}

/**
  * own_isalpha - function that checks if char is alpha
  * @f:- the char to check
  * Return:- Always 0
  */

int own_isalpha(int f)
{
	if (((f >= 97) && (f <= 122)) || ((f >= 65) && (f <= 90)))
		return (1);

	else
		return (0);
}

/**
  * own_strcmp - fuction that cmp two str
  * @sizeone:- first str
  * @sizetwo:- secomd str
  * Return:- Always 0
  */

int own_strcmp(char *sizeone, char *sizetwo)
{
	int lengthone = own_strlen(sizeone);
	int lengthtwo = own_strlen(sizetwo);
	int comp = 0;
	int j = 0;


	if (sizeone == NULL || sizetwo == NULL)
	{
		return (1);
	}

	if (lengthone != lengthtwo)
	{
		return (1);
	}

	for (; sizeone[j]; j++)
	{
		if (sizeone[j] != sizetwo[j])
		{
			comp = sizeone[j] - sizetwo[j];
			break;
		}
		else
		{
			continue;
		}
	}


	return (comp);
}
