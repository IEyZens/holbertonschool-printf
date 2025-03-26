#include "main.h"

/**
 * print_integer - prints an integer (decimal)
 * @args: argument to print
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
	/* Récupère l'entier depuis la liste d'arguments */
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	/* Nombre de caractères imprimés (au minimum 1 pour le dernier chiffre) */
	int i = 1;
	/* Si le nombre est négatif, on affiche '-' et on convertit n en positif */
	if (n < 0)
	{
		/* Affiche le signe négatif */
		_putchar('-');
		/* Convertit n en positif */
		n = -n;
		/* On compte le caractère '-' */
		i++;
	}
	/* Enlève le dernier chiffre pour traiter le reste du nombre */
	num = n / 10;

	while (num > 0)
	{
		/* Augmente la puissance de 10 (10, 100, 1000, ...) */
		exp *= 10;
		/* Réduit num pour trouver la puissance maximale */
		num /= 10;
	}
	/* Affiche les chiffres un par un en partant du plus grand */
	while (exp > 0)
	{
		/* Extrait le chiffre le plus à gauche */
		digit = n / exp;
		/* Convertit le chiffre en caractère ASCII et l'affiche */
		_putchar(digit + '0');
		n -= digit * exp;
		exp /= 10;
		i++;
	}
	_putchar(last + '0');

	return (i);
}
