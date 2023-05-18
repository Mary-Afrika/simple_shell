#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
char **get_directories(void);
void handle_command(char *command);
char *get_path(char *path);
char **splitstring(char *str, char *delim);
void print_environment();
char *_getenv(const char *name);
int handle_custom_commands(char *command);

#endif
