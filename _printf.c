#include "mainf.h"
#include <stdio.h>
/**
 * _printf - Prints  standar output like regular printf
 * @form:  printed adn its format specifiers string
 *
 * Return: The Length of printed string
 */
int _printf(const char *form, ...)
{
	va_list args_list;
	char flag;
	int i = 0, len = 0;

	va_start(args_list, form);
	if (!form)
		return (-1);
	while (form[i])
	{
		if (form[i] != '%')
			len += _putcharacter(form[i]);
		else
		{
			i++;
			if (!form[i])
				return (-1);
			if (form[i] == '+' || form[i] == ' ' || form[i] == '#')
			{
				flag = form[i];
				i++;
				len += _flags_handler(args_list, flag, form[i]);
			}
			else
				len += _specifier_handler(args_list, form[i]);
		}
		i++;
	}

	va_end(args_list);

	return (len);
}

/**
 * _specifier_handler - Does the handling for specifier passed to _printf
 *
 * @args_list: List of var arguments
 * @specifier: specifier after %
 * Return: length of handle arg
 */
int _specifier_handler (va_list args_list, char specifier)
{
	int len = 0;

	if (specifier == 'c')
		len += _putcharacter(va_arg(args_list, int));
	else if (specifier == 's')
		len += _putstr(va_arg(args_list, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += _putinteger(va_arg(args_list, int));
	else if (specifier == 'b')
		len += _putbit(va_arg(args_list, unsigned int));
	else if (specifier == '%')
		len += _putcharacter('%');
	else if (specifier == 'u')
		len += _putunsingedinteger(va_arg(args_list, unsigned int));
	else if (specifier == 'o')
		len += _putoctal(va_arg(args_list, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += _puthexadecimal(va_arg(args_list, int), specifier);
	else if (specifier == 'S')
		len += _putnospecifier(va_arg(args_list, char *));
	else
		len += _printf("%%%c", specifier);
	return (len);
}

/**
 * _flags_handler - handles a specifierifier to _printf
 *
 * @args_list: List of var arguments
 * @specifier: specifierifier
 * @base: base var
 * Return: length of handle arguments
 */
int _flags_handler(va_list args_list, char specifier, char base)
{
	int len = 0;

	if (specifier == '+')
		len += _putsigned(va_arg(args_list, int), base);
	else if (specifier == ' ')

		len += _putspaced(va_arg(args_list, int), base);
	else if (specifier == '#')
		len += _puthash(va_arg(args_list, unsigned int), base);
	return (len);
}
