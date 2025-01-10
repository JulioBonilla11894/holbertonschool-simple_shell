#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

/**
 * _values_path - Searches for a command in the directories listed in the PATH.
 * @command: A pointer to the command string.
 * @env: The environment variables.
 *
 * Return: 1 if the command is found in the directories in PATH, 0 if not.
 */

int _values_path(char **command, char **env)
{
	char *path = NULL, *path_dup = NULL, *path_token = NULL;
	struct stat st;
	int i;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
	}
	if (!path)
	return (0);
	path_dup = strdup(path);
	if (!path_dup)
	return (0);
	path_token = strtok(path_dup, ":");
	while (path_token)
	{
		char *full_path = malloc(strlen(path_token) + strlen(*command) + 2);

		if (!full_path)
		{
			free(path_dup);
			return (0);
		}
		sprintf(full_path, "%s/%s", path_token, *command);
		if (stat(full_path, &st) == 0)
		{
			free(*command);
			*command = full_path;
			free(path_dup);
			return (1);
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	free(path_dup);
	return (0);
}
