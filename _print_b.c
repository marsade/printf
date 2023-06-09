#include "main.h"
/**
 * _printf_b - prints a number in binary
 * @ap: arguments
 * Return: length
*/
int _printf_b(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[BUFFER_SIZE];
	int len = print_number(n, buffer, 2);

	write(1, buffer, len);
	return (len);
}
