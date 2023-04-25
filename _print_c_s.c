#include "main.h"
/**
  * _print_c - prints a single char
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
  * _print_s - prints a string
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
