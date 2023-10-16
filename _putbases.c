#include "main.h"

/**
 * _putbit - Prints an binary value to standard output
 * @numb: unsigned number for print
 *
 * Return: Length of string printed - 1
 */
 
int _putbit(unsigned int numb)
{
	int len = 0;
	unsigned int val;

	if (!numb)
	{
		len += _putcharacter('0');
		return (len);
	}
	val = numb % 2;
	numb = numb / 2;
	if (numb)
		len += _putbit(numb);
	len += _putcharacter(val + '0');

	return (len);
}

/**
 * _putoctal - Prints octal stdr output
 * @numb: The number to print
 *
 * Return: Length of string printed - 1
 */
int _putoctal(unsigned int numb)
{
	int len = 0;
	unsigned int val;

	if (numb < 8)
	{
		len += _putinteger(numb);
		return (len);
	}
	val = numb % 8;
	numb = numb / 8;
	if (numb)
		len += _putoctal(numb);
	len += _putcharacter(val + '0');

	return (len);
}

/**
 * _puthexadecimal - Prints a hex stdr output
 * @numb: The number print
 * @alpha: alpha
 * Return: Length of string printed - 1
 */
int _puthexadecimal(unsigned int numb, char alpha)
{
	int len = 0;
	unsigned int val;

	if (numb < 10)
		return (_putcharacter(numb + '0'));
	if (numb < 16)
	{
		if (alpha == 'x')
			return (_putcharacter(numb + 87));
		return (_putcharacter(numb + 55));
	}
	val = numb % 16;
	numb = numb / 16;
	if (numb)
		len += _puthexadecimal(numb, alpha);
	len += _puthexdecimal(val, alpha);

	return (len);
}

