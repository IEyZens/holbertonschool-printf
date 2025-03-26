#include "main.h"

/**
 * print_char - function print char
 * @args: is a variable list
 * Return: 1
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - function print string
 * @args: is a variable list
 * Return: len
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (!s)
		s = "(null)";

	while (s[len])
	{
		_putchar(s[len]);
		len++;
	}

	return (len);
}

/**
 * print_int - function print int
 * @args: is a variable list
 * Return: count
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;
	char buffer[12];
	int i = 0, j;
	unsigned int n;

	if (num < 0)
	{
		count += _putchar('-');
		n = -num;
	}
	else
	{
		n = num;
	}

	do {
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	} while (n > 0);

	for (j = i - 1; j >= 0; j--)
		count += _putchar(buffer[j]);

	return (count);
}

/**
 * print_dec - function print dec
 * @args: is a variable list
 * Return: print_int(args)
 */
int print_dec(va_list args)
{
	return (print_int(args));
}
