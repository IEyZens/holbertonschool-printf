#include "main.h"

/**
 * print_char- a function for _printf function
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
 * print_string- a function for _printf function
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
 * _printf - a function that produces output according to a format
 * @format: is a character string. The format string is composed of zero or
 * more directives
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */

int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);

			i++;
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars = print_string(args);
			else if (format[i] == '%')
				printed_chars += _putchar('%');
			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
			}
		}
		else
		{
			printed_chars += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}
