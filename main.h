#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list val);
int print_string(va_list val);
int print_int(va_list args);
int print_dec(va_list args);


#endif /* MAIN_H */
