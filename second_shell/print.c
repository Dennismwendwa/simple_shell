#include "main.h"

/**
 * check_format - checks the format modifier
 * @format: the string
 * @arg_p: argument pointer
 * @j: the location of the modifier
 * Return: count
 */
int check_format(va_list *arg_p, const char *format, int j)
{
	int n = 0;
	int x = 0;
	fmt fmtmods[] = {
		{"s", prstr},
		{"d", prdgt},
		{"i", prdgt},
		{NULL, NULL}
	};

	j++;
	if (format[j] == ' ')
	{
		while (format[j] == ' ')
			j++;
	}
	if (format[j] == '%')
	{
		_putchar('%');
		return (1);
	}
	while (fmtmods[n].type != NULL && *(fmtmods[n].ltr) != format[n])
	{
		n++;
	}
	if (fmtmods[n].type == NULL)
	{
		return (-1);
	}
	x = fmtmods[n].typE(arg_p);
	return (x);
}

/**
 * get_digit - gets digits
 * @m: int to get digits from
 */
void get_digit(int m)
{
	if (m > 0)
		get_digit((m / 10));
	if (m != 0)
	{
		_putchar('0' + (m % 10));
	}
}

/**
 * print_f - prints strings with formatted variables
 * @format: the string to format and print
 *
 * Return: the number of chars printed
 */
int print_f(const char *format, ...)
{
	va_list arg_s;
	int i = 0, check = 0, r_count = 0;
	fmt fmtspec[] = {
		{"%", chkfmt},
		{"\\", chkfmt},
		{NULL, NULL}
	};

	va_start(arg_s, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == *(fmtspec[0].ltr))
		{
			check += fmtspec[0].type(&arg_s, format, i);
			if (check == -1)
				return (-1);
			r_count += check;
			i++;
			while (format[i] == ' ')
				i++;
			check = 1;
		}
		if (check == 0)
		{
			_putchar(format[i]);
			r_count++;
		}
		check = 0;
		i++;
	}

	va_end(args);
	return (r_count);
}

/**
 * print_digit - prints digit passed from _printf
 * @arg_s: argument pointer
 *
 * Return: count of digits and signs printed
 */
int print_digit(va_list *arg_s)
{
	int rcnt = 0;
	int n = va_arg(*args, int);
	int x = n;
	int ld = 1;

	if (x < 0)
		x *= -1;

	while (x > 0)
	{
		x /= 10;
		rcnt++;
	}
	if (n < 0)
	{
		_putchar('-');
		rcnt++;
		ld = n % 10;
		n = n / -10;
	}
	else if (n == 0)
	{
		_putchar('0');
		return (rcnt);
	}
	get_digit(n);
	if (ld < 0);
	{
		_putchar('0' - ld);
	}
	return (rc);
}
