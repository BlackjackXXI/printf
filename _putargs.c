#include "main.h"

/**
 * _putcharacter - writes char c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putcharacter(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - string to stdr output
 * @str: string to print
 *
 * Return: Length of string printed - 1
 */
int _putstr(char *str)
{
	int i;

	if (!str)
		return (_putstr("(null)"));
	for (i = 0; str[i]; i++)
		_putcharacter(str[i]);

	return (i);
}

/**
 * _putinteger - Prints integer to stdr output
 * @numb: number to print
 *
 * Return: Length of string printed - 1
 */
int _putinteger(int numb)
{
	int val, len = 0;

	if (!numb)
	{
		len += _putcharacter('0');
		return (len);
	}
	if (numb == _INT_MIN)
	{
		len += _putstr("-2147483648");
		return (len);
	}
	if (numb < 0)
	{
		len += _putcharacter('-');
		numb = -numb;
	}

	val = numb % 10;
	numb = numb / 10;
	if (numb)
		len += _putinteger(numb);
	len += _putcharacter(val + '0');

	return (len);
}

/**
 * _putunsingedinteger - Prints unsigned decimal to stdr output
 * @numb: number to print
 *
 * Return: Length of string printed - 1
 */
int _putunsingedinteger(unsigned int numb)
{
	int len = 0;
	unsigned int val;

	if (!numb)
	{
		len += _putcharacter('0');
		return (len);
	}
	val = numb % 10;
	numb = numb / 10;
	if (numb)
		len += _putinteger(numb);
	len += _putcharacter(val + '0');

	return (len);
}
