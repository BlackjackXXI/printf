#include "main.h"
#include <stdio.h>
/**
 * _printf - Prints stdtoi 
 * @format: string and spec print
 *
 * Return: Length of printed string
 */
int _printf(const char *format, ...)
{
	va_list ls_args;
	char flag;
	int i = 0, len = 0;

	va_start(ls_args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			len += _putchar(format[i]);
		else
		{
			i++;
			if (!format[i])
				return (-1);
			if (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				flag = format[i];
				i++;
				len += _flag_handler(ls_args, flag, format[i]);
			}
			else
				len += _spec_handler(ls_args, format[i]);
		}
		i++;
	}

	va_end(ls_args);

	return (len);
}


/**
 * _flag_handler - flags handler to printf
 *
 * @ls_args: Listof arguments
 * @spec: specifier
 * @base: basee
 * Return:  len
 */
int _flag_handler(va_list ls_args, char spec, char base)
{
	int len = 0;

	if (spec == '+')
		len += _putsign(va_arg(ls_args, int), base);
	else if (spec == ' ')

		len += _putspace(va_arg(ls_args, int), base);
	else if (spec == '#')
		len += _puthash(va_arg(ls_args, unsigned int), base);

	return (len);
}


/**
 * _spec_handler - specifier handker
 *
 * @ls_args: args list
 *
 * Return: len
 */
int _spec_handler (va_list ls_args, char spec)
{
	int len = 0;

	if (spec == 'c')
		len += _putchar(va_arg(ls_args, int));
	else if (spec == 's')
		len += _putstr(va_arg(ls_args, char *));
	else if (spec == 'd' || spec == 'i')
		len += _putint(va_arg(ls_args, int));
	else if (spec == 'b')
		len += _putbit(va_arg(ls_args, unsigned int));
	else if (spec == '%')
		len += _putchar('%');
	else if (spec == 'u')
		len += _putuint(va_arg(ls_args, unsigned int));
	else if (spec == 'o')
		len += _putoct(va_arg(ls_args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		len += _puthex(va_arg(ls_args, int), spec);
	else if (spec == 'S')
		len += _putnospec(va_arg(ls_args, char *));
	else
		len += _printf("%%%c", spec);

	return (len);
}
