#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int _values_path(char **command, char **env)
{
    char *path = NULL, *path_dup = NULL, *path_token = NULL;
    struct stat st;
    int i; /* Declare loop variable outside the for loop */

    /* Find the PATH environment variable */
    for (i = 0; env[i]; i++)
    {
        if (strncmp(env[i], "PATH=", 5) == 0) /* Use standard strncmp */
        {
            path = env[i] + 5; /* Skip "PATH=" */
            break;
        }
    }
    if (!path) /* PATH not found */
        return (0);

    /* Duplicate PATH to tokenize */
    path_dup = strdup(path);
    if (!path_dup)
        return (0);

    /* Tokenize PATH and check each directory */
    path_token = strtok(path_dup, ":");
    while (path_token)
    {
        char *full_path = malloc(strlen(path_token) + strlen(*command) + 2);
        if (!full_path)
        {
            free(path_dup);
            return (0);
        }

        /* Build the full path */
        sprintf(full_path, "%s/%s", path_token, *command);
        if (stat(full_path, &st) == 0) /* Check if the file exists */
        {
            free(*command); /* Free the old command */
            *command = full_path; /* Update command with the full path */
            free(path_dup);
            return (1); /* Command resolved */
        }

        free(full_path);
        path_token = strtok(NULL, ":");
    }

    free(path_dup);
    return (0); /* Command not found in PATH */
}
