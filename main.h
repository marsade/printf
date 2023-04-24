#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
int _printf(const char *format, ...);
typedef struct format
{
	char *id;
	int (*f)(va_list);
}conversion;
int _print_c(va_list ap);
int _print_s(va_list ap);
int _strlen(char *s);
int _strlenc(const char *s);
int _printf_d(va_list ap);
int _printf_i(va_list ap);
#endif
