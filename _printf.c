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
	int i = 0, printed_chars = 0, len;
	va_list args;
	char c, *s;
	char unknown[2];

	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return(-1);
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
				len = strlen(s);
				_putchar(*s);
				printed_chars += len;
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				unknown[0] = '%';
				unknown[1] = format[i];
				_putchar(unknown[0]);
				_putchar(unknown[1]);
				printed_chars += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}

