#include "shell.h"

/**
* _strncmp - compare strings
* @s1: character pointer
* @s2: character pointer
* @n: The maximum number of characters to compare
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
{
    len++;
}
len++;
copy = malloc(sizeof(char) * (len));
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
return ((char *)s);
s++;
}

return (NULL);
}
