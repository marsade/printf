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
