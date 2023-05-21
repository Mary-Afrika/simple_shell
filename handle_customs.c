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
	if (_strcmp(command, "exit") == 0)
	{
		my_exit(args);
		return (1);
	}
	else if (_strcmp(command, "setenv") == 0)
	{
		if (args[1] && args [2])
		{
			_setenv(args[1], args[2], 1);
		} else {
			fprintf(stderr, "Setenv failed. Invalid arguments.\n");
		}
		return (1);
	}
	else if (_strcmp(command, "unsetenv") == 0)
	{
		if (args[1])
		{
			_unsetenv(args[1]);
		} else {
			fprintf(stderr, "Unsetenv failed. Invalid arguments.\n");
		}
		return (1);
	}

	else if (_strcmp(command, "cd") == 0)
	{
		change_directory(args);
		return (1);
	}
else
	{
		return (-1);
	}
}

/**
 * change_directory - changes directory suitably
 * @args: string array of input promt
 * Return: void
*/
void change_directory(char **args)
{
	char cwd[256];
	char *home_dir;
	char *old_dir;

	home_dir = getenv("HOME");
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		printf("getcwd error");
		return;
	}

	if (args[1] == NULL)
	{
		chdir(home_dir);
	}
	else
	{
		if (_strcmp(args[1], "-") == 0)
		{
			old_dir = getenv("OLDPWD");
			if (old_dir != NULL)
			{
				chdir(old_dir);
				printf("%s\n", old_dir);
			}
			else
			{
				printf("cd: OLDPWD not set\n");
			}
		}
		else
		{
			if (chdir(args[1]) == -1)
			{
				printf("cd: %s: No such file or directory\n", args[1]);
			}
		}
	}
}

