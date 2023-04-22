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
	};
	va_list args;
	int i, j = 0, len = 0, len2 = 0;
	len2 = _strlenc(format);

	va_start(args, format);

	while (format[i] != '\0' && format != NULL)
	{
		while (j <= 2)
		{
			if (convert[j].id[0] == format[i] && convert[j].id[1] == format[i + 1])
			{
				len += convert[j].f(args);
				i = i + 2;
			}
			j++;
		}
		write(1, &format[i], len2);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
int main(void)
{
	int len;
	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Length:[%d, %i]\n", len, len);
	return (0);
}