#include "main.h"

/**
 * _putint - prints integers 
 * @num: printed num
 *
 * Return: Length of printed strngs 
 */
int _putint(int num)
{
	int val, len = 0;

	if (!num)
	{
		len += _putchar('0');
		return (len);
	}
	if (num == _INT_MIN)
	{
		len += _putstr("-2147483648");
		return (len);
	}
	if (num < 0)
	{
		len += _putchar('-');
		num = -num;
	}

	val = num % 10;
	num = num / 10;
	if (num)
		len += _putint(num);
	len += _putchar(val + '0');

	return (len);
}


/**
 * _putchar - prints to stdrio
 * @c: character var
 *
 * Return: len
 * 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints to stdrio
 * @str: The string
 *
 * Return: len
 */
int _putstr(char *str)
{
	int i;

	if (!str)
		return (_putstr("(null)"));
	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * _putuint - decimal to stdrio output
 * @num: The number
 * Return: len
 */
int _putuint(unsigned int num)
{
	int len = 0;
	unsigned int val;

	if (!num)
	{
		len += _putchar('0');
		return (len);
	}
	val = num % 10;
	num = num / 10;
	if (num)
		len += _putint(num);
	len += _putchar(val + '0');

	return (len);
}
