#include "main.h"
/**
 * _printf_u - prints integer unsigned
 * @ap: argument
 * Return: length of characters
 */
int _printf_u(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char buffer[BUFFER_SIZE];
	int len = print_number(num, buffer, 10);

	write(1, buffer, len);
}
/**
 * _printf_x - prints unsigned hexadecimal
 * @ap: argument
 * Return: length of characters
 */
int _printf_x(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[BUFFER_SIZE];
	int len = print_number(n, buffer, 16);

	write(1, buffer, len);
	return (len);
}
/**
 * _printf_o - prints unsigned octal
 * @ap: argument
 * Return: length of characters
 */
int _printf_o(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[BUFFER_SIZE];
	int len = print_number(n, buffer, 8);

	write(1, buffer, len);
	return (len);
}
/**
 * _printf_X - prints capital hexadecimal
 * @ap: argument
 * Return: length of characters
 */
int _printf_X(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[BUFFER_SIZE], temp;
	int i = 0, len = 0, remainder, j;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n != 0)
		{
			remainder = n % 16;
			if (remainder < 10)
				buffer[i++] = remainder + '0';
			else
				buffer[i++] = remainder + 'A' - 10;
			n = n / 16;
		}
	}
	len = i;

	for (j = 0; j < i / 2; j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
	write(1, buffer, len);
	return (len);
}
