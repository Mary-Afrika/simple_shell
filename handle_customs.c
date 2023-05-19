#include "shell.h"

/**
 * handle_custom_commands - handles custom commands
 * beyond the built in commands
 * @command: the cammand arg , args[0]
 * Return: 1- on error else 1
*/
int handle_custom_commands(char *command)
{
	if (strcmp(command, "env\n") == 0)
	{
		printf("This is env\n");
		return (1);
	}
	else
	{
		return (-1);
	}
}
