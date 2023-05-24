#include "main.h"

/**
  * counting_digt - function that cnt dgts
  * @number:- number to count
  * Return:- Always 0
  */

size_t counting_digt(size_t number)
{
	size_t digitcount = 0;

	while (number != 0)
	{
		number /= 10;
		digitcount++;
	}

	return (digitcount);
}

/**
  * own_itoa - function that changes num to str
  * @ba:- string base
  * @buff:- arry of str
  * @num:- input
  * Return:- Always 0
  */

char *own_itoa(size_t num, char *buff, int ba)
{
	int sign = 1;
	int idx = 0;
	size_t rem = 0;

	if (num == 0)
	{
		buff[idx++] = '0';
		buff[idx] = '\0';
	}
	while (num)
	{
		rem = num % ba;
		buff[idx++] = '0' + rem;
		num /= ba;
	}
	if (sign < 0)
	{
		buff[idx++] = '-';
	}

	buff[idx] = '\0';
	return (reverse_string(buff));
}











































































