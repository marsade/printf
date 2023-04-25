#include "main.h"
/**
 * print_number - prints an integer using the specified base
 * @n: the integer to print
 * @base: the base to use (e.g. 10 for decimal, 16 for hex)
 * @buffer: space for the buffer
 * Return: the number of characters printed
 */
int print_number(unsigned int n, char *buffer, int base)
{
	const char digits[] = "0123456789abcdef";
	char *p = buffer;
	char tmp;
	int len = 0, i = 0, j;

	if (n == 0)
	{
		*p++ = '0';
		len++;
	}
	else
	{
		while (n != 0)
		{
			*p++ = digits[n % base];
			n /= base;
			len++;
		}
	}

	*p = '\0';

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
	}
	return (len);
}
/**
 * hex_cast - converts non-printable characters to hexadecimal
 * @num: character to be converted
 * Return : counter
*/
int hex_cast(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		write(1, &array[i], 1);
	}
	free(array);
	return (counter);

}