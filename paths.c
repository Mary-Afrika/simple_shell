#include "shell.h"

/**
 * get_path - takes path from promt and checks if path is valid. Returns
 * the valid path, else null
 * @path: the partial path of to be checked if valid
 * Return: return a pointer to the path string, else NULL
*/
char *get_path(char *path)
{
	char *full_path = NULL;
	char **dirs = get_directories();
	struct stat st;
	int i;

	for (i = 0; dirs[i]; i++)
	{
		full_path = malloc(strlen(path) + strlen(dirs[i]) + 2);

		if (!full_path)
		{
			printf("Memory Allocation Failed");
			return (NULL);
		}
		strcat(full_path, dirs[i]);
		strcat(full_path, "/");
		strcat(full_path, path);
		strcat(full_path, "\0");

		if (stat(full_path, &st) == 0)
		{
			return (full_path);
		}
		else
		{
		  free(full_path);
		}
	}
	if (stat(path, &st) == 0)
	{
		return (path);
	}
	return (NULL);
}


/**
 * get_directories - returns array of directories in PATH
 * Return: char**, a string array of the directories
 */
char **get_directories(void)
{
	char *path = getenv("PATH");
	char **dirs;
	int i = 0;
	char *dir;

	if (path == NULL)
	{
		printf("PATH not set\n");
		return (NULL);
	}
	dirs = malloc(1024 * sizeof(char *));
	if (!dirs)
	{
		printf("Malloc fialed");
		return (NULL);
	}
	dir = _strtok(strdup(path), ":");
	while (dir != NULL && i < 1024)
	{
		dirs[i] = dir;
		i++;
		dir = _strtok(NULL, ":");
	}
	dirs[i] = NULL;

	return (dirs);
}
