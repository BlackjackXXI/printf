#include "main.h"

/**
 * _puthex2 - hex  stdr output
 * @numb: number
 * Return: len
 */
int _puthex2(int num)
{
	int val;

	if (numb < 10)
	{
		_putchar('0');
		_putchar(numb + '0');
		return (2);
	}
	if (numb < 16)
	{
		_putchar('0');
		_putchar(numb + 55);
		return (2);
	}

	val = numb % 16;
	numb = numb / 16;

	_puthex(numb, 'X');
	_puthex(val, 'X');

	return (2);
}


/**
 * _putnospec - output
 * @str: strng 
 *
 * Return: len
 */
int _putnospec(char *str)
{
	int i, len = 0;

	if (!str)
		return (len += _putstr("(null)"));
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			len += _putchar(92);
			len += _putchar('x');
			len += _puthex2(str[i]);
			continue;
		}
		len += _putchar(str[i]);
	}

	return (len);
}