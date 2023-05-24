
#include "main.h"

/**
  * own_strlen - function that checks length of string
  * @x:- pointer to the string
  * Return:- Always 0
  */
/*
int own_strlen(char *x)
{
	int g = 0;

	for (; x[g] != '\0'; g++)
		continue;

	return (g);
}*/

/**
  * own_atoi - changes to number
  * @x:- the string to chane
  * Return:- Always 0
  */
/*
int own_atoi(char *x)
{
	int c;
	int a;
	int b;
	int d = 1;

	a = c = 0;

	while ((x[a] < '0' || x[a] > '9') && (x[a] != '\0'))
	{
		if (x[a] == '-')
		{
			d *= -1;
		}
		a++;
	}

	b = a;

	while ((x[b] >= '0') && (x[b] <= '9'))
	{
		c = (c * 10) + d * ((x[b]) - '0');
		b++;
	}

	return (c);
}*/



/**
  * _putchar - function that prints characters
  * @k:- character to print
  * Return:- Always 0
  */

int _putchar(char k)
{

	return (write(1, &k, 1));
}


/**
  * own_strncpy - function that cpy strings
  * @l:- number of char to cpy
  * @kbq:- pointer of the string
  * @kwenda:- new string
  * Return:- Always 0
  */
/*
char *own_strncpy(char *kwenda, char *kbq, int l)
{
	int k = 0;

	while (k < l && *(kbq + k))
	{
		*(kwenda + k) = *(kbq + k);
		k++;
	}

	while (k < l)
	{
		*(kwenda + k) = '\0';
		k++;
	}


	return (kwenda);
}
*/
/**
  * _putts - function that prints strs
  * @kbq:- pointer to the strng
  * Return:- Always 0
  */
/*
void _putts(char *kbq)
{
	int j = 0;

	for (; kbq[j] != '\0'; j++)
		_putchar(kbq[j]);

	_putchar('\n');

	return;

}*/
