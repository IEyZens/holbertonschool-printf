#include "main.h"

/**
 * _printf - Fonction qui produit une sortie selon un format
 * @format: Chaîne de caractères contenant le format
 *
 * Return: Nombre total de caractères imprimés
 */
int _printf(const char *format, ...)
{
	/* i permet de parcourir la chaîne de format et printed_chars est un compteur */
	int i = 0, printed_chars = 0;
	va_list args;

	/* Vérifie si format est NULL */
	if (!format)
		return (-1);

	va_start(args, format);
	/* Parcours la chaîne de format */
	while (format[i])
	{
		/* Vérifie s'il y a un spécificateur de format */
		if (format[i] == '%')
		{
			/* Vérifie si '%' est le dernier caractère */
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}

			/* Passe au caractère suivant '%' */
			i++;
			/* Gestion d'un caractère */
			if (format[i] == 'c')
				printed_chars += print_char(args);
			/* Gestion d'une chaîne de caractères */
			else if (format[i] == 's')
				printed_chars += print_string(args);
			/* Gestion du double '%' */
			else if (format[i] == '%')
				printed_chars += _putchar('%');
			/* Gestion des entiers */
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_int(args);
			/* Si le spécificateur est inconnu, on affiche le caractère brut */
			else
			{
				printed_chars += _putchar('%');
				printed_chars += _putchar(format[i]);
			}
		}
		/* Si ce n'est pas un caractère '%', on imprime le caractère */
		else
		{
			printed_chars += _putchar(format[i]);
		}
		i++;
	}
	/* Termine la gestion des arguments variables */
	va_end(args);
	/* Retourne le nombre total d'arguments imprimés */
	return (printed_chars);
}
