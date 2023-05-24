#include "shell.h"

/**
* my_exit - exit the program with a specified status
* @args: command arguments
*/

void my_exit(char *command, char **args)
{
int status = 0;
long int str_result;
static int error_num = 1;

if (args[1])
{
str_result = custom_atoi(args[1]);
if (str_result == 0)
{
printf("sh: %d: exit: Illegal number: %s\n", error_num++, args[1]);
return;
}
status = str_result;
}
free(args);
free(command);
exit(status);
}
