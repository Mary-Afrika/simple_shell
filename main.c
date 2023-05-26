#include "shell.h"

/**
 * main - main function
 * @ac: num on args
 * @av: array of args
 * Return: int
 */
int main(int ac, char **av)
{
	char *command = NULL;
	char *prompt = "$ ";
	size_t promt_length;
	size_t buff_size;
	size_t getline_err;
	int err_count = 1;
	int status = 0;
	(void)err_count;

	(void)ac;
	command = NULL;
	buff_size = 0;
	getline_err = -1;

	if (isatty(STDIN_FILENO)) /* is terminal ?*/
	{
		while (1)
		{
			write(1, prompt, _strlen(prompt));
			promt_length = getline(&command, &buff_size, stdin);
			if (promt_length == getline_err)
			{
				return (-1);
			}
			handle_command(command, av, &status);
		}
	}
	else
	{
		while (getline(&command, &buff_size, stdin) != -1)
		{
			handle_command(command, av, &status);
		}
		printf("here --%d--\n", status);
		exit(status);
	}
	free(command);
	return (0);
}

/**
 * handle_command - handles a command, a long string
 * @command: char array of the command
 * @av: char array
 * @status: error status
 * Return: 1 if successful, else -1
 */
int handle_command(char *command, char **av, int *status)
{
	char *path = NULL;
	char **args = NULL;
	char *delim = " \n";
	int custom_res = -1;

	if (_strlen(command) == 1)
	{
		return (-1);
	}
	args = splitstring(command, delim);
	if (args && args[0])
	{
		custom_res = handle_custom_commands(command, args, av, status);
		if (custom_res == -1)
		{
			path = get_path(args[0]);
			if (path)
			{
				execute(args, path, status);
			}
			else
			{
				perror(av[0]);
			}
		}
	}
	free(args);
	return (-1);
}
/**
 * execute - executes commands using execve
 * @args: arrya
 * @path: path
 * @status: error status
 * Return: int
 */
int execute(char **args, char *path, int *status)
{
	pid_t pid;
	int res;

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
			return (-1);
		}
		else
		{
			perror("Memory allocation failed");
			free(path);
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &res, 0);
		if (WIFEXITED(res) && WEXITSTATUS(res) == 0)
		{
			*status = WEXITSTATUS(res);
			free(path);
			return (1);
		}
		else
		{
			*status = WEXITSTATUS(res);
			free(path);
			return (-1);
		}
	}
}
