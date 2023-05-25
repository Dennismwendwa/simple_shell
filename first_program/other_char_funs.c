
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
