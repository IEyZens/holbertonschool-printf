#include "main.h"

/**
<<<<<<< HEAD
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
 * print_integer - imprimer un entier (décimal)
 * @args: argument à imprimer
 * Return: nombre d'arguments imprimés
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

/**
=======
>>>>>>> d0d220677153f5b93b73f6ef213930ba03feb7fb
 * _printf - Fonction qui produit une sortie selon un format
 * @format: Chaîne de caractères contenant le format
 *
 * Return: Nombre total de caractères imprimés
 */
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0;
	va_list args;

	if (!format) /* Vérifier si la chaîne de format est NULL */
		return (-1);

<<<<<<< HEAD
	va_start(args, format); /* Initialiser la liste des arguments variables */

	while (format[i]) /* Parcourir la chaîne de format */
=======
	va_start(args, format);
	while (format[i])
>>>>>>> d0d220677153f5b93b73f6ef213930ba03feb7fb
	{
		if (format[i] == '%') /* Détection d'un spécificateur de format */
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}

			i++; /* Passer au caractère suivant après '%' */
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
			else if (format[i] == '%')
				printed_chars += _putchar('%');
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_int(args);
			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
			}
		}
		else /* Caractère normal à afficher directement */
		{
			printed_chars += _putchar(format[i]);
		}
		i++;
	}
<<<<<<< HEAD

	va_end(args); /* Nettoyer la liste des arguments variables */
	return (printed_chars); /*Retourner le nombre total de caractères imprimés*/
=======
	va_end(args);
	return (printed_chars);
>>>>>>> d0d220677153f5b93b73f6ef213930ba03feb7fb
}
