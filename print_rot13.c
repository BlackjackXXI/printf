#include "main.h"
#include <stdio.h>

/**
 * print_R - function prints string in rot13
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_R(va_list args)
{
	int i, count = 0, j, flag = 0;
	char arr1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char arr2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(args, char *);

	for (i = 0; s[i]; i++)
	{
		flag = 0;
		for (j = 0; arr1[j] && !flag; j++)
		{
			if (s[i] == arr1[j])
			{
				_putchar(arr2[j]);
				count++;
				flag = 1;
			}
		}
		if (!flag)
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
