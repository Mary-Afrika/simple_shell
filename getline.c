#include "shell.h"

/**
* my_getline - a custom getline function
* @lineptr: pointer to the buffer
* @n: memory to be allocated, 0 means allocate 'dynamically'
* @stream: stream type
* Return: number of characters read
*/
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
ssize_t buffer_idx;
size_t buffer_size;
char *buffer = NULL;
char *newlinePtr = NULL;
buffer_idx = 0;
buffer_size = 0;
if (lineptr == NULL || n == NULL || stream == NULL)
{
return (-1);
}
while (1)
{
if (buffer_size == 0)
{
buffer_size = 1028;
buffer = malloc(buffer_size);
if (buffer == NULL)
{
return (-1);
}
}
buffer_idx = getline(&buffer, &buffer_size, stream);
if (buffer_idx == -1)
{
if (errno == EINTR)
continue;
else
return (-1);
}
else if (buffer_idx == 0)
{
if (buffer_size == 0)
{
free(buffer);
return (-1);
}
break;
}
if (buffer[buffer_idx - 1] == '\n')
{
newlinePtr = buffer + buffer_idx - 1;
break;
}
}
if (newlinePtr != NULL)
*newlinePtr = '\0';
*lineptr = buffer;
*n = buffer_size;
return newlinePtr != NULL ? (newlinePtr - buffer + 1) : buffer_idx;
}
