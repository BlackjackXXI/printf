#include "MAIN.h"
#include <stdio.h>

/**
 * print_c - function prints char
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_c(va_list args)
{
	_putchar(va_arg(args, int));
	/* prints only one character */
	return (1);
}

/**
 * print_s - function prints string
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_s(va_list args)
{
	int i;
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		s = "(null)";
	}
	for (i = 0; s[i]; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * print_perc - function prints % sign
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_perc(__attribute__((unused)) va_list args)
{
	_putchar('%');
	/* one character printed */
	return (1);
}
