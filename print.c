#include "shell.h"

/**
 *print - prints an input string
 *@str: the string to be printed
 *
 * Return: void
 */
void print(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned
 */
int _putchar(char c)
{
	static int i;
	static char buf[1024];

	if (c == -1 || i >= 1024)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
}