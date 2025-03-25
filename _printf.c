#include "main.h"

/**
 * print_char - Imprime un caractère
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - Imprime une chaîne de caractères
 * @args: Liste d'arguments
 * Return: Nombre de caractères imprimés
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
 * _printf - Fonction qui produit une sortie selon un format
 * @format: Chaîne de caractères contenant le format
 *
 * Return: Nombre total de caractères imprimés
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
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}

			i++;
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
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
