#include "shell.h"

void my_exit(char **args)
{
    int status = 0;
    long int str_result;
    char *terminate;
    static int error_num = 1;

    errno = 0;
    if (args[1])
    {
        str_result = strtol(args[1], &terminate, 10);
        if (errno != 0 || *terminate != '\0')
        {
            printf("sh: %d: exit: Illegal number: %s\n", error_num++, args[1]);
            return;
        }
        status = (int)str_result;
    }
    exit(status);
}