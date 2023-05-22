#include "shell.h"

/**
* _isdigit - checks whether a given input is a digit
* @term: a char int parameter
* Return: 1 if c is a digit, 0 otherwise
*/

int _isdigit(int term)
{
if (term >= 48 && term <= 57)
{
return (1);
}
else
return (0);
}
