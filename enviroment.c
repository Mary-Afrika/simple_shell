#include "shell.h"

/**
 * _getenv - gets the current env using environ
 * @name: name of the enviroment variable to be gotten
 * Return: string of the env value
 */
char *_getenv(const char *name)
{
	char **env = NULL;
	size_t name_length;

	if (name == NULL)
		return (NULL);
	name_length = strlen(name);
	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
			return (&((*env)[name_length + 1]));
		}
	}
	return (NULL);
}
void print_environment(void)
{
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		printf("%s\n", *env);
	}
}
