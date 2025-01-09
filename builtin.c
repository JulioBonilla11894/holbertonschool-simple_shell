#include "shell.h"

/**
 * _getenv - Prints the environment variables
 * @env: Environment variables
 */

void _getenv(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
