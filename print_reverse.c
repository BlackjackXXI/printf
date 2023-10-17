#include "main.h"
#include <stdio.h>

/**
 * print_r - function prints string in reverse
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_r(va_list args)
{
	int i = 0, count = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[i])
		i++;
	count = i;
	i--;
	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	return (count);
}
