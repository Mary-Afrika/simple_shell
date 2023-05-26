#include "shell.h"

/**
* my_exit - exit the program with a specified error_no
* @command: string
* @args: command arguments
* @av: main input
* @status: error num
*/
void my_exit(char *command, char **args, char **av, int *status)
{
int error_no = 0;
long int str_result;
static int error_num = 1;
char err_ch;

(void)status;
if (args[1])
{
str_result = custom_atoi(args[1]);
if (str_result == 999999 || str_result < 0)
{
err_ch = (char)error_num;
(void)err_ch;
fprintf(stderr, "%s: %d: exit: Illegal number: %s\n", av[0],
		error_num++, args[1]);
return;
}
error_no = str_result;
}
else
{
	error_no = *status;
}
free(args);
free(command);
exit(error_no);
}
