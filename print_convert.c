#include "main.h"
#include <stdio.h>

/**
 * print_conv - function converts input to specified base
 * @num: the input number
 * @base: the specified base
 * @cap: a flag to print hex in capital. 0 is lowercase
 * Return: number of characters printed
 */
char *print_conv(unsigned long int num, int base, int cap)
{
	char *outputString = "0123456789abcdef";
	char *capitalString = "0123456789ABCDEF";
	char arr[50];
	char *ptr;

	ptr = &arr[49];
	*ptr = '\0';

	if (cap)
		outputString = capitalString;
	do	{
		*--ptr = outputString[num % base];
		num /= base;
	} while (num);
	return (ptr);
}

/**
 * print_u - function converts input to decimal and prints
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *conv;

	conv = print_conv(num, 10, 0);
	return (_printf("%s", conv));
}

/**
 * print_o - function converts input to octal and prints
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *conv;

	conv = print_conv(num, 8, 0);
	return (_printf("%s", conv));
}

/**
 * print_x - function converts input to lowercase hex and prints
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_x(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *conv;

	conv = print_conv(num, 16, 0);
	return (_printf("%s", conv));
}

/**
 * print_X - function converts input to uppercase hex and prints
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *conv;

	conv = print_conv(num, 16, 1);
	return (_printf("%s", conv));
}
