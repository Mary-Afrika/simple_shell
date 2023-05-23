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
	char *command_split;
	size_t promt_length;
	size_t buff_size;
	size_t getline_err;
	const char *command_separator = ";";

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
		command_split = strtok(command, command_separator);
		while (command_split != NULL)
		{
			handle_and_or(command_split);
			command_split = strtok(NULL, command_separator);
		}
	}
	free(command);
	return (0);
}

/**
 * handle_command - handles a command, a long string
 * which is split up and executed
 * is a valid command
 * @command: char array of the command
 * Return: 1 if successful, else -1
 */
int handle_command(char *command)
{
	char *path = NULL;
	pid_t pid;
	char **args = NULL;
	char *delim = " \n";
	int custom_res = -1;
	int status;

	if (_strlen(command) == 1)
	{
		return (-1);
	}

	args = splitstring(command, delim);

	if (args)
	{
		custom_res = handle_custom_commands(args[0], args);

		if (custom_res == -1)
		{
			path = get_path(args[0]);

			if (path)
			{
				pid = fork();
				if (pid == -1)
				{
					free_char_array(args);
					free(path);
					return (-1);
				}
				else if (pid == 0)
				{
					if (execve(path, args, environ) == -1)
					{
						perror("An Error has occurred\n");
						exit(0);
						return (-1);
					}
					else
					{
						printf("%s: command not found\n", args[0]);
						free(path);
						return (-1);
					}
				}
				else
				{
					waitpid(pid, &status, 0); 

					if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
					{
						free_char_array(args);
						free(path);
						return (1); 
					}
					else
					{
						free_char_array(args);
						free(path);
						return (-1); 
					}
				}
			}
			else
				printf("%s: command not found\n", args[0]);
		}
	}
	free_char_array(args);
	return (-1);
}
