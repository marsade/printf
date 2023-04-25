#include "main.h"
/**
  * _printf_c - prints a single char
  * @ap: arguments passed into the function
  * Return: 1
  */
int _printf_c(va_list ap)
{
	char s;

	s = va_arg(ap, int);
	write(1, &s, 1);
	return (1);
}
/**
  * _printf_s - prints a string
  * @ap: arguments passed into the function
  * Return: length of string
  */
int _printf_s(va_list ap)
{
	char *s;
	int len = 0;

	s = va_arg(ap, char *);
	len = _strlen(s);

	if (s == NULL)
	{
		s = "(null)";
		write(1, "(null)", 5);
	}

	write(1, s, len);
	return (len);
}
/**
 * _printf_S - prints exclusive string
 * @ap: argument
 * Return: length of string
*/
int _printf_S(va_list ap)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			write(1, "\\x", 2);
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				write(1, "0", 1);
				len++;
			}
			len = len + hex_cast(cast);
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
	}
	return (len);

}
