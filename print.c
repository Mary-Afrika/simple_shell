#include "shell.h"

/**
 * print_err - prints an error to stderr
 * @str: string to be printed
 * Return: void
 */
void print_err(char *str)
{
	int idx;

	if (str != NULL)
	{
		idx = 0;
		while (str[idx] != '\0')
		{
			put_err(str[idx]);
			idx++;
		}
	}
}
/**
 * put_err - putchar to stderr
 * @ch: chat
 * Return: void
 */
void put_err(char ch)
{
	static char buffer[1024];
	static int buffer_idx;

	if (ch == '\n' || buffer_idx >= 1024)
	{
		write(2, buffer, buffer_idx);
		write(2, "\n", 1);
		buffer_idx = 0;
	}
	else
	{
		buffer[buffer_idx] = ch;
		buffer_idx++;
	}
}
