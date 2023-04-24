#include "main.h"
/**
 * _printf_d - prints an integer
 * @ap: arguments passed into the function
 * Return: length of argument
 */
int _printf_d(va_list ap);
{
	int i;

	i = va_arg(ap, int);

