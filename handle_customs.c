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
	else if (strcmp(command, "setenv") == 0)
	{
		if (args[1] && args [2])
		{
			_setenv(args[1], args[2], 1);
		} else {
			fprintf(stderr, "Setenv failed. Invalid arguments.\n");
		}
		return (1);
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		if (args[1])
		{
			_unsetenv(args[1]);
		} else {
			fprintf(stderr, "Unsetenv failed. Invalid arguments.\n");
		}
		return (1);
	}
	else
	{
		return (-1);
	}
}
