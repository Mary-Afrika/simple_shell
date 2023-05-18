#include "shell.h"

/**
 * main - main function
 * @ac: num on args
 * @av: array of args
 * Return: int
 */
int main(int ac, char **av)
{
	char *command;
	const char *promt;
	size_t promt_length;
	size_t buff_size;
	size_t getline_err;

	(void)ac;
	(void)av;
	command = NULL;
	promt = "#cisfun$ ";
	buff_size = 1024;
	getline_err = -1;

	while (1)
	{
		printf("%s", promt);
		promt_length = getline(&command, &buff_size, stdin);
		if (promt_length == getline_err)
		{
			return (-1);
		}
		if (strcmp(command, "exit\n") == 0)
		{
			return (-1);
		}
		handle_command(command);
	}
	free(command);
	return (0);
}

/**
 * handle_command - handles a command, a long string
 * which is split up and executed
 * is a valid command
 * @command: char array of the command
 * Return: void
 */
void handle_command(char *command)
{
	char *path = NULL;
	pid_t pid;
	char **args = NULL;
	char *delim = " \n";

	if (strlen(command) == 1)
	{
		return;
	}

	args = splitstring(command, delim);

	if (args)
	{
		path = get_path(args[0]);

		if (path)
		{
			pid = fork();
			if (pid == -1)
			{
				return;
			}
			else if (pid == 0)
			{
				if (execve(path, args, environ) == -1)
					perror("An Error has occurred\n");
				else if (handle_custom_commands(args[0]) == -1)
					printf("%s: command not found\n", args[0]);
				exit(0);
			}
			else
			{
				wait(NULL);
				return;
			}
		}
		else
			printf("%s: command not found\n", args[0]);
	}
}
