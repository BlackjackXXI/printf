#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1)
	{
		write(1, &buffer, i);
		i = 0;
	}
	else
	{
		buffer[i] = c;
		i++;
	}
	return (1);
}
