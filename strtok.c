#include "shell.h"

/**
* _strtok - custom strtok function
* @str: char pointer of the str
* @delim: delimeters for splitting
* Return: token after splitting
*/
char *_strtok(char *str, const char *delim)
{
static char *head;
char *token;

if (str != NULL)
{
head = str;
}

if (head == NULL || *head == '\0')
return (NULL);

token = head;

while (*head != '\0' && _strchr(delim, *head) != NULL)
head++;

if (*head == '\0')
return (NULL);

token = head;

while (*head != '\0' && _strchr(delim, *head) == NULL)
head++;

if (*head != '\0')
{
*head = '\0';
head++;
}

return (token);
}
