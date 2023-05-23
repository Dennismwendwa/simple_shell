
#include "main.h"

/**
  * _putchar - function that write char
  * @c:- the char to write
  * Return:- Always 0
  */

int _putchar(char c)
{
	return (write(2, &c, 1));
}

/**
  * prstring - function that write str
  * @args: ptr to args
  * Return:- Always 0
  */

int prstring(va_list *args)
{
	char *car;
	int b = 0;

	car = va_arg(*args, char *)
	{
		_putchar(*car);
		b++;
		car++;
	}

	return (b);
}


/**
  * _putts - function that prints chars
  * @string:- the str to print
  * Return:- Always 0
  */

void _putts(char *string)
{
	while (*string != '\0')
	{
		write(1, string, 1);
		string++;
	}
}
