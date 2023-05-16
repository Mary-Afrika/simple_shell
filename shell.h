#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char **get_directories(void);
void handle_command(char *command);
char *get_path(char *path);
char **splitstring(char *str, char *delim);

#endif
