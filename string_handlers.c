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
		tokens[tokenCount] = _strdup(token);
		tokenCount++;
		token = _strtok(NULL, delim);
	}
	tokens[tokenCount] = NULL;
	return (tokens);
}


/**
 * _strlen - length of string
 * @s: string input
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}

	return (i);
}

/**
 * _strcat - cancatenate strings
 * @dest: char pointer
 * @src: char pointer
 * Return: char pointer
 */
char *_strcat(char *dest, char *src)
{
	int dest_idx = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[dest_idx + i] = src[i];
		i++;
	}
	dest[dest_idx + i] = '\0';
	return (dest);
}

int custom_atoi(char *string)
{
    int res;
    int sign;
    int i;

	res = 0;
	sign = 1;
	i = 0;
    if (string[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; string[i] != '\0'; i++)
    {
        if (!_isdigit(string[i]))
        {
            return 0; 
        }

        res = res * 10 + (string[i] - '0');
    }

    return sign * res;
}

/**
 * _strcmp - compare strings
 * @s1: character pointer
 * @s2: character pointer
 * Return: int
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0, ret;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
			break;
	}

	ret = s1[i] - s2[i];
	return (ret);
}

/**
 * _strcmp - compare strings
 * @s1: character pointer
 * @s2: character pointer
 * Return: int
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;
	int ret;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
			break;
	}

	ret = s1[i] - s2[i];
	return (ret);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: source string
 * Return: returns a pointer to the duplicated string else NULL
 * Remember to free the return string
 */
char *_strdup(char *str)
{
	char *copy;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	copy = (char *)malloc((sizeof(char) * len) + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';

	return (copy);
}

/**
 * _strcpy - copies text to dest
 * @dest: destination array
 * @src: source array
 * Return: pointer to destination array
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string
 * @c: character to locate
 * Return: a pointer to the first occurrence of the character
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (char *)s;
		s++;
	}

	return (NULL);
}
