#include "main.h"
/**
 * print_number - prints an integer using the specified base
 * @n: the integer to print
 * @base: the base to use (e.g. 10 for decimal, 16 for hex)
 * @caps: a flag indicating whether to use uppercase letters for hex digits
 * Return: the number of characters printed
 */
int print_number(unsigned int n, char *buffer, int base)
{
    static char digits[] = "0123456789abcdef";
    char *p = buffer;
	char tmp;
    int len = 0;
	int i = 0, j;

    if (n == 0) {
        *p++ = '0';
        len++;
    } else {
        while (n != 0) {
            *p++ = digits[n % base];
            n /= base;
            len++;
        }
    }

    *p = '\0';

    for (i = 0, j = len - 1; i < j; i++, j--) {
        tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
    }

    return len;
}