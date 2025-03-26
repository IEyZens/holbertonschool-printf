#include "main.h"

/**
 * print_integer - prints an integer (decimal)
 * @args: argument to print
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int i = 1;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		i++;
	}
	num = n / 10;

	while (num > 0)
	{
		exp *= 10;
		num /= 10;
	}
	while (exp > 0)
	{
		digit = n / exp;
		_putchar(digit + '0');
		n -= digit * exp;
		exp /= 10;
		i++;
	}
	_putchar(last + '0');

	return (i);
}
