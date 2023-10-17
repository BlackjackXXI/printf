#include "MAIN.h"
#include <stdio.h>

/**
 *print_helper - prints input as printf would do
 * @format: a character string containing directives
 * @ptbl: table of functions
 * @args: list of arguments
 * Return: The number of characters printed
 */

int print_helper(const char *format, print_table ptbl[], va_list args)
{
	int i = 0, j, count = 0, done = 0, ret;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i])
	{
		for (; format[i] != '%'; i++, count++)
		{
			if (!format[i])
			{
				done = 1;
				break;
			}
			_putchar(format[i]);
		}
		if (done)
			break;
		i++;
		for (j = 0; ptbl[j].type; j++)
			if (format[i] == ptbl[j].type)
			{
				ret = ptbl[j].func(args);
				if (ret == -1)
				{
					return (-1);
				}
				count += ret;
				break;
			}
		if (ptbl[j].type == 0)
		{
			if (!format[i])
				break;
			_putchar('%');
			_putchar(format[i]);
			count += 2;
		}
		i++;
	}
	return (count);
}

/**
 *_printf - prints input as printf would do
 * @format: a character string containing directives
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	print_table ptbl[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_perc},
		{'d', print_d},
		{'i', print_i},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'S', print_S},
		{'r', print_r},
		{'p', print_p},
		{'R', print_R},
		{0, NULL}
	};
	va_start(args, format);

	count = print_helper(format, ptbl, args);
	_putchar(-1);
	va_end(args);
	return (count);
}
