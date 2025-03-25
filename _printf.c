#include "main.h"

/**
 * printf - a function that produces output according to a format
 * @format: is a character string. The format string is composed of zero or
 * more directives
 * @is: composed of zero or more directives
 *
 * Returns: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */

int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list args;
	char c, *s;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
			{
				va_end(args);
				return (-1);
			}

			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (*s)
				{
					_putchar(*s++);
					printed_chars++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}
