#include "shell.h"

/**
 * handle_custom_commands - handles custom commands
 * beyond the built in commands
 * @command: the cammand arg , args[0]
 * Return: 1 if found else -1
*/
int handle_custom_commands(char *command, char **args)
{
	(void)args;
	if (strcmp(command, "exit") == 0)
	{
		my_exit(args);
		return (1);
	}
	else
	{
		return (-1);
	}
}
