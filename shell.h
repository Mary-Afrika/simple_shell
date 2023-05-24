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
int handle_command(char *command);
char *get_path(char *path);
char **splitstring(char *str, char *delim);
void print_environment(void);
char *_getenv(const char *name);
int handle_custom_commands(char *command, char **args);
char *_strtok(char *str, const char *delim);
void my_exit(char **args);
int _unsetenv(char *name);
int _setenv(char *name, char *value, int overwrite);
void change_directory(char **args);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int custom_atoi(char *string);
int _isdigit(int term);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strchr(const char *s, char c);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void free_char_array(char **array);
void handle_and_or(char *command);
void print(char *str);
int _putchar(char c);
int execute(char **args, char *path);

#endif
