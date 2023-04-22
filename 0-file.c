#include "main.h"
#include <unistd.h>
/**
 * _printf - function that producees output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *s;
	int c, len = 0, i = 0, len2 = 0;

	while (format[len2] != '\0')
	{
		len2++;
	}
	va_start(args, format);
	while (format[i] != '\0' && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					break;
				case 's':
					s = va_arg(args, char *);
					while (s[len] != '\0')
					{
						len++;
					}
					write(1, s, len);
					break;
				default:
					i++;
					continue;
			}
		}
		else
			write(1, format, 1);
		i++;
	}
	va_end(args);
	return (len2);
}
