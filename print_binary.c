#include "main.h"

/**
 * print_b - function converts unsigned integer argument
 * to binary
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_b(va_list args)
{
	int i = 0, count = 0;
	int arr[32] = {0};
	unsigned int num = va_arg(args, unsigned int);

	if (!num)
	{
		_putchar('0');
		count++;
	}
	while (num)
	{
		arr[i] = num % 2;
		i++;
		num /= 2;
	}
	i--;
	while (i >= 0)
	{
		_putchar(arr[i] + '0');
		count++;
		i--;
	}
	return (count);
}
