#include "shell.h"


void handle_and_or(char *command)
{
    const char *command_or = "||";
    const char *command_and = "&&";
    char *command_partial_and = NULL;
    char *command_partial_or = NULL;
    int exec_result;
    int previous_exec;

    if (strstr(command, command_and))
    {
        command_partial_and = strtok(_strdup(command), command_and);
        previous_exec = 1;
        while (command_partial_and != NULL)
        {
            if (previous_exec == 1)
            {
                exec_result = handle_command(command_partial_and);
                previous_exec = exec_result;
            }
            command_partial_and = strtok(NULL, command_and);
        }
    }
    else if (strstr(command, command_or))
    {
        command_partial_or = strtok(_strdup(command), command_or);

        previous_exec = -1;

        while (command_partial_or != NULL)
        {
            if (previous_exec == -1){
                exec_result = handle_command(command_partial_or);
                previous_exec = exec_result;
            }
            command_partial_or = strtok(NULL, command_or);
        }
    } else {
        handle_command(command);
    }
}
