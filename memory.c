#include "shell.h"

/**
* free_char_array - frees memory allocated for a string array
* @arr: the string array to free
* Return: void
*/
void free_char_array(char **arr)
{
	int i;

	if (arr)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
