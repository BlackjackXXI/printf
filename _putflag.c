#include "main.h"

/**
 * _putsigned - prints a signed 
 * @numb: number of signs
 * @specifier: specifier
 * Return: length
 */
int _putsigned(int numb, char specifier)
{
	int len = 0;

	if (specifier == 'd' || specifier == 'i')
	{
		if (numb >= 0)
			len += _putcharacter('+');
		len += _putinteger(numb);
	}
	else if (specifier == 'u')
		len += _putuinteger(numb);

	return (len);
}

/**
 * _putspaced - prints a space
 *
 * @numb: number of spaces
 * @specifier: the specifier
 * Return: len
 */
int _putspaced(int numb, char specifier)
{
	int len = 0;

	if (specifier == 'd' || specifier == 'i')
	{
		if (numb >= 0)
			len += _putcharacter(' ');
		len += _putinteger(numb);
	}
	else if (specifier == 'u')
		len += _putuinteger(numb);

	return (len);
}

/**
 * _puthash - prints a hash
 * @numb: number
 * @base: base of number
 * Return: len
 */
int _puthash(unsigned int numb, char base)
{
	int len = 0;

	if (base == 'o')
	{
		len += _putcharacter('0');
		len += _putoctal(numb);
	}
	else if (base == 'x')
	{
		len += _putstr("0x");
		len += _puthexadecimal(numb, 'x');
	}
	else if (base == 'X')
	{
		len += _putstr("0X");
		len += _puthexadecimal(numb, 'X');
	}

	return (len);
}

