#include "main.h"

/**
 * _putoct - octal to stdr output
 * @num: printed num
 *
 * Return: len
 */
int _putoct(unsigned int num)
{
	int len = 0;
	unsigned int val;

	if (num < 8)
	{
		len += _putint(num);
		return (len);
	}
	val = num % 8;
	num = num / 8;
	if (num)
		len += _putoct(num);
	len += _putchar(val + '0');

	return (len);
}

/**
 * _putbit - binary standard output
 * @num: unsigned number
 *
 * Return: len
 */
int _putbit(unsigned int num)
{
	int len = 0;
	unsigned int val;

	if (!num)
	{
		len += _putchar('0');
		return (len);
	}
	val = num % 2;
	num = num / 2;
	if (num)
		len += _putbit(num);
	len += _putchar(val + '0');

	return (len);
}


/**
 * _puthex - hex standard output
 * @num: number 
 * @alpha: alpha value
 * Return: len
 */
int _puthex(unsigned int num, char alpha)
{
	int len = 0;
	unsigned int val;

	if (num < 10)
		return (_putchar(num + '0'));
	if (num < 16)
	{
		if (alpha == 'x')
			return (_putchar(num + 87));
		return (_putchar(num + 55));
	}
	val = num % 16;
	num = num / 16;
	if (num)
		len += _puthex(num, alpha);
	len += _puthex(val, alpha);

	return (len);
}

