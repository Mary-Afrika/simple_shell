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

/**
* custom_atoi - Converts a string to an integer.
*
* @string: The string to convert to an integer.
* Return: the converted integer value.
*/

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
return (0);
}

res = res * 10 + (string[i] - '0');
}

return (sign *res);
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
