#include "main.h"

/**
 * print_char - function print char
 * @args: is a variable list
 * Return: 1
 */
int print_char(va_list args)
{
	/* Récupère l'argument sous forme de caractère */
	char c = va_arg(args, int);

	/* Affiche le caractère */
	_putchar(c);
	/* Retourne le nombre de caractère imprimés */
	return (1);
}

/**
 * print_string - function print string
 * @args: is a variable list
 * Return: len
 */
int print_string(va_list args)
{
	/* Récupère l'argument sous forme de chaîne */
	char *s = va_arg(args, char *);
	int len = 0;

	/* Gère le cas où la chaîne est NULL */
	if (!s)
		/* Remplace NULL par "(null)" pour éviter un comportement indéfini */
		s = "(null)";

	/* Parcours la chaîne et affiche chaque caractère */
	while (s[len])
	{
		_putchar(s[len]);
		len++;
	}

	/* Retourne le nombre de caractère imprimés */
	return (len);
}

/**
 * print_int - function print int
 * @args: is a variable list
 * Return: count
 */
int print_int(va_list args)
{
	/* Récupère l'argument sous forme d'entier */
	int num = va_arg(args, int);
	int count = 0;
	/* Tampon pour stocker les chiffres de l'entier (assez grand pour un int) */
	char buffer[12];
	int i = 0, j;
	unsigned int n;

	/* Vérifie si l'entier est négatif */
	if (num < 0)
	{
		/* Affiche le signe moins */
		count += _putchar('-');
		/* Convertit en valeur absolue pour la gestion des chiffres */
		n = -num;
	}
	else
	{
		/* Garde la valeur telle quelle si elle est positive */
		n = num;
	}

	/* Conversion de l'entier en chaîne inversée dans buffer */
	do {
		/* Stocke le chiffre sous forme de caractère */
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	} while (n > 0);

	/* Affichage des chiffres dans l'ordre correct */
	for (j = i - 1; j >= 0; j--)
		/* Affiche chaque caractère stocké dans buffer */
		count += _putchar(buffer[j]);

	/* Retourne le nombre de caractères imprimés */
	return (count);
}
