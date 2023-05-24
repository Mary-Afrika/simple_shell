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
char **dirs;
struct stat st;
int i;

dirs = get_directories();

for (i = 0; dirs[i]; i++)
{
full_path = malloc(_strlen(path) + _strlen(dirs[i]) + 2);

if (!full_path)
{
perror("Memory Allocation Failed");
return (NULL);
}
_strcat(full_path, dirs[i]);
_strcat(full_path, "/");
_strcat(full_path, path);
_strcat(full_path, "\0");

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
free_char_array(dirs);
return (_strdup(path));
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
char *path_copy;

if (path == NULL)
{
perror("PATH not set\n");
return (NULL);
}
dirs = malloc(1024 * sizeof(char *));
if (!dirs)
{
	perror("Malloc fialed");
	return (NULL);
}
path_copy = _strdup(path);
if (!path_copy)
{
perror("Memory Allocation Failed");
free_char_array(dirs);
return (NULL);
perror("Memory Allocation Failed");
	return (NULL);
}
dir = strtok(path_copy, ":");
while (dir != NULL && i < 1024)
{
dirs[i] = _strdup(dir);
i++;
dir = strtok(NULL, ":");
}
dirs[i] = NULL;
return (dirs);
}
