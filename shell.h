#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;
char **get_directories(void);
void handle_command(char *command);
char *get_path(char *path);
char **splitstring(char *str, char *delim);
void print_environment(void);
char *_getenv(const char *name);
int handle_custom_commands(char *command, char **args);
char *_strtok(char *str, const char *delim);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void my_exit(char** args);
int _unsetenv(char *name);
int _setenv(char *name, char *value, int overwrite);

#endif
