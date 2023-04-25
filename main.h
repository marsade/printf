#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
int _printf(const char *format, ...);
/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */
typedef struct format
{
	char *id;
	int (*f)(va_list);
} conversion;
int _print_c(va_list ap);
int _print_s(va_list ap);
int _strlen(char *s);
int _strlenc(const char *s);
int _printf_d(va_list ap);
int _printf_i(va_list ap);
#endif