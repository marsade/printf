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
	for (1 = 0; i < len / 2; i++)
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
	int n = va_arg(ap, int);
	int num, last = n % 10, digit;
	int i = 1;
	int exp = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		write(1, "-", 1);
		num = -num;
		n = -n;
		last = -last;
		i++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}

		num = n;

		while (exp > 0)
		{
			digit = num / exp;
			write(1, &digit, 1);
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}

	write(1, &last, 1);

	return (i);
}
