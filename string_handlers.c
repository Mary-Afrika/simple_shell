#include "shell.h"

/**
 * splitstring - splits string into array of substrings based on delimiter
 * @str: string to be splitted
 * @delim: delimeter for separation
 * Return: array of splitted strings
*/
char **splitstring(char *str, char *delim)
{
	char **tokens = malloc(1024 * sizeof(char *));
	char *token;
	int tokenCount = 0;

	if (tokens == NULL)
	{
		return (NULL);
	}
	token = _strtok((char *)str, delim);
	while (token != NULL && tokenCount < 1024)
	{
		tokens[tokenCount] = strdup(token);
		tokenCount++;
		token = _strtok(NULL, delim);
	}
	tokens[tokenCount] = NULL;
	return (tokens);
}
