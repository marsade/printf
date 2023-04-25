#include "main.h"
/**
 * _printf_u - prints integer unsigned
 * @ap: argument
 * Return: length of characters
 */
int _printf_u(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	int len = 0, digit;
	int reversed_num;
	int is_negative = 0;
	char digit_char;

	if (num == 0)
	{
		num = 0;
		write(1, "0", 1);
		return (1);
	}

	reversed_num = 0;
	while (num != 0)
	{
		reversed_num = reversed_num * 10 + num % 10;
		num /= 10;
	}

	while (reversed_num != 0)
	{
		digit = reversed_num % 10;
		digit_char = digit + '0';
		write(1, &digit_char, 1);
		reversed_num /= 10;
		len++;
	}

	return (len + is_negative);
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
