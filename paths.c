#include "shell.h"

char *get_path(char *command) {
    char *path = getenv("PATH");
	char *dir = NULL;
	char *path_copy = NULL;
	struct stat st;
	char *valid_path = NULL;
	char *full_path = NULL;

    if (path == NULL) {
        perror("Unable to access the PATH environment variable.");
        return (NULL);
    }

	if (stat(command, &st) == 0) /*check if a path on its own*/
	{
        return _strdup(command);
    }

    path_copy = _strdup(path);
    if (path_copy == NULL) {
        perror("strdup: ");
        return (NULL);
    }
    dir = strtok(path_copy, ":");
    while (dir != NULL) {
		full_path = malloc((_strlen(dir) + _strlen(command) + 2) * sizeof(char));
		if (full_path == NULL) {
			perror("malloc: ");
			return (NULL);
		}
		strcat(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

        if (stat(full_path, &st) == 0) {
            valid_path = _strdup(full_path);
			break;
        }
        dir = strtok(NULL, ":");
		free(full_path);
    }
	free(full_path);
	free(path_copy);
    return (valid_path);
}
