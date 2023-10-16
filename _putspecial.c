#include "main.h"

/**
 * _putnospecifier - Prints a string to stdr output
 * @str: The string to be printed
 *
 * Return: Length of string printed - 1
 */
int _putnospecifier(char *str)
{
	int i, len = 0;

	if (!str)
		return (len += _putstr("(null)"));
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			len += _putcharacter(92);
			len += _putcharacter('x');
			len += _puthexadecimal2(str[i]);
			continue;
		}
		len += _putcharacter(str[i]);
	}

	return (len);
}

/**
 * _puthexadecimal2 - Prints a hexadecimal to stdr output
 * @numb: The number
 * Return: Length of string printed - 1
 */
int _puthexadecimal2(int num)
{
	int val;

	if (numb < 10)
	{
		_putcharacter('0');
		_putcharacter(numb + '0');
		return (2);
	}
	if (numb < 16)
	{
		_putcharacter('0');
		_putcharacter(numb + 55);
		return (2);
	}

	val = numb % 16;
	num = numb / 16;

	_puthexadecimal(numb, 'X');
	_puthexadecimal(val, 'X');

	return (2);
}
