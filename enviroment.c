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
	name_length = _strlen((char *)name);
	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
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

int _setenv(char *name, char *value, int overwrite)
{
    char *env_var;
	size_t new_env_length;
	char *new_env;
	int res;

    if (name == NULL || value == NULL)
    {
        return (-1);
    }

    env_var = getenv(name);
    if(env_var != NULL && overwrite == 0)
    {
        return (0);
    }

    new_env_length = _strlen(name) + _strlen(value) + 2;
    new_env = malloc(new_env_length * sizeof(char *));

    if(!new_env)
    {
        return (-1);
    }
    _strcat(new_env, name);
    _strcat(new_env, "=");
    _strcat(new_env, value);
    _strcat(new_env, "\0");
    
    res = putenv(new_env);

    return (res);
}

int _unsetenv(char *name) {
	size_t nameLength;
	int i;
	int j;

    if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL) {
        return -1;
    }
    nameLength = _strlen(name);

    for (i = 0; environ[i] != NULL; i++) {
        if (_strncmp(environ[i], name, nameLength) == 0 && environ[i][nameLength] == '=') {
            for (j = i; environ[j] != NULL; j++) {
                environ[j] = environ[j + 1];
            }
            return 0;
        }
    }
    return 0;
}