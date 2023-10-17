#include <stdio.h>
#include "main.h"

/**
 * print_p - function prints an address
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_p(va_list args)
{
	unsigned long int adr = va_arg(args, unsigned long int);
	char *str;

	str = print_conv(adr, 16, 0);
	if (!adr)
		return (_printf("(nil)"));
	return (_printf("0x%s", str));
}
