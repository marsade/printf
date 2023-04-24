#include "main.h"

/**
 * _printf_d - prints an integer
 * @ap: arguments passed into the function
 *
 * Return: length of argument
 */
int _printf_d(va_list ap)
{
	int num = va_arg(ap, int);
	char buffer[50], temp;
	int len = 0;
	int is_negative = num < 0 ? 1 : 0;
	int copy, digit_count, digit, i;

	if (is_negative)
	{
		buffer[len++] = '-';
		num = -num;
	}

	copy = num;
	digit_count = 0;

	do {
		digit_count++;
		copy /= 10;
	} while (copy);

	for (i = 0; i < digit_count; i++)
	{
		digit = num % 10;
		num /= 10;
		buffer[len++] = digit + '0';
	}
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	write(1, buffer, len);

	return (len);
}
/**
 * _printf_i - prints an integer
 * @ap: arguments passed into the function
 *
 * Return: length of argument
 */
int _printf_i(va_list ap)
{
	int num = va_arg(ap, int);
	int len = 0, digit;
	int reversed_num;
	int is_negative = 0;
	char digit_char;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
		write(1, "-", 1);
		len++;
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
