#include "main.h"

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_d(va_list args)
{
	int i, count = 0;
	int input = va_arg(args, int);
	unsigned int abs, current;

	if (input < 0)
	{
		abs = -input;
		_putchar('-');
		count++;
	}
	else
		abs = input;
	current = abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs / i)
		{
			_putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	_putchar('0' + current);
	count++;

	return (count);
}

/**
 * print_i - function prints an integer (base 10)
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_i(va_list args)
{
	return (print_d(args));
}
