#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024

int _putchar(char c);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct convert- defines a structure of symbol to function
 * @sym: the operator
 * @f: this is function to associated
 */

/* Définition d'un alias pour struct convert */
typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} conver_t;

/* Fonctions de support */

/* Déclarations des fonctions utilisées dans _printf */
int recording_error(const char *format, conver_t f_list[], va_list arg_list);
/* Fonction principale imitant printf */
int _printf(const char *format, ...);
/* ecrit un caractere */
int _write_char(char);
/* Affiche un caractère depuis une liste d'arguments */
int print_char(va_list);
/* Affiche une chaîne de caractères */
int print_string(va_list);
/* Affiché le symbole % */
int print_percent(va_list);
/* Affiché un entier signé */
int print_integer(va_list);
/* Affiché un nombre */
int print_number(va_list);
/*  Convertit un nombre en binaire et l'affiche */
int print_binary(va_list);
/* Affiché un entier non signé */
int print_unsigned_integer(va_list);
/* Affiche un entier non signé sans liste d'arguments */
int print_unsigned_number(unsigned int);
/* Affiche une chaîne inversée */
int print_reversed(va_list);

/**
 * base_len - Calculates the length of a number in a given base
 * @num: The number whose length is being calculated
 * @base: The base used for conversion
 *
 * Return: The length of the number in the given base
 */
unsigned int base_len(unsigned int num, int base);
/* inverse une chaine de caractere */
char *rev_string(char *);
/* Écrit un nombre dans une base spécifique */
void write_base(char *str);
/* Copie n octets de str vers dest */
char *_memcpy(char *dest, char *str, unsigned int n);

#endif /* MAIN_H */
