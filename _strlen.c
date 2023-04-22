#include "main.h"
/**
* _strlen - function that returns the length of a string
* @s: string to be checked
* Return: length of string
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * _strlenc - returns the length of the string constant
 * @s: the string
 * Return: the length of the string constant
*/
int _strlenc(const char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
