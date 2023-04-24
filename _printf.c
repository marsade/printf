#include "main.h"
/**
 * _printf - function that producees output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	conversion convert[] = {
		{"%c", _print_c},
		{"%s", _print_s},
		{"%d", _printf_d},
		{"%i", _printf_i},
	};
	va_list args;
	int i, j = 0, len = 0;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		j = sizeof(convert) / sizeof(conversion) - 1;
		while (j >= 0)
		{
			if (convert[j].id[0] == format[i] && convert[j].id[1] == format[i + 1])
			{
				len += convert[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		write(1, &format[i], 1);
		len++;
		i++;
	}

Here:
	va_end(args);
	return (len);
}
