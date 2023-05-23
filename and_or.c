#include "shell.h"

/**
* handle_and_or - handle commands containing logical operators (&& and ||)
* @command: the command to handle
*/
void handle_and_or(char *command)
{
const char *command_or = "||";
const char *command_and = "&&";
char *command_partial_and = NULL;
char *command_partial_or = NULL;
int exec_result;
int previous_exec;
char *command_or_copy = NULL;
char *command_and_copy = NULL;

if (strstr(command, command_and))
{
	command_and_copy = strdup(command);
	command_partial_and = strtok(command_and_copy, command_and);
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
	free(command_and_copy);
}
else if (strstr(command, command_or))
{
	command_or_copy = strdup(command);
	command_partial_or = strtok(command_or_copy, command_or);
	previous_exec = -1;

while (command_partial_or != NULL)
{
if (previous_exec == -1)
{
exec_result = handle_command(command_partial_or);
previous_exec = exec_result;
}
command_partial_or = strtok(NULL, command_or);
}
free(command_or_copy);
}
else
{
handle_command(command);
}
}
