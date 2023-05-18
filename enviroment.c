#include "shell.h"

char *_getenv(const char *name) {
    char **env = NULL;
    size_t name_length;

    if (name == NULL)
        return NULL;
    name_length = strlen(name);
    for (env = environ; *env != NULL; ++env) {
        if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=') {
            return &((*env)[name_length + 1]);
        }
    }
    return NULL;
}
void print_environment() {
    char **env;

    for (env = environ; *env != NULL; ++env) {
        printf("%s\n", *env);
    }
}