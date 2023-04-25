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
	char buffer[BUFFER_SIZE], temp;
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
	if (num == 0)
	{
		num = 0;
		write(1, "0", 1);
		return (1);
	}

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
	long int n = va_arg(ap, long int);
	char buffer[BUFFER_SIZE];
	int len = 0;

	if (n == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			write(1, "-", 1);
		}
		len += print_number(n, buffer + len, 10);
		
	}
	write(1, buffer, len);
	return (len);

}
