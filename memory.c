#include "shell.h"

/**
* free_char_array - frees memory allocated for a string array
* @array: the string array to free
* Return: void
*/
void free_char_array(char **array)
{
int i;

if (array == NULL)
return;

for (i = 0; array[i] != NULL; i++)
{
free(array[i]);
}
free(array);
}
