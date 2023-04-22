#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
int _printf(const char *format, ...);
typedef struct format
{
	char *id;
	int (*f)();
}conversion;
int _strlen(char *s);
#endif
