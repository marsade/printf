#include "main.h"
/**
 * _printf_p - prints an address
 * @ap: arguments
 * Return: length
 */
int _printf_p(va_list ap)
{
	char *p = "0x";
	unsigned long ptr = va_arg(ap, unsigned long);
	char buffer[BUFFER_SIZE];
	int len = 0;

	if (ptr == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
	}
	else
		len = print_number((unsigned int) ptr, buffer, 16);
	write(1, prefix, 2);
	len += 2;
	write(1, buffer, len);

	return (len);
}
